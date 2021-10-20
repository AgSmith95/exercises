#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.hpp"

#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <vector>
#include <map>

using lock_t = std::unique_lock<std::mutex>;
using timestamp = std::chrono::time_point<std::chrono::steady_clock>;

struct TaskID {
    timestamp tp;
    Task task;
    unsigned worker{};

    TaskID() = default;
    TaskID(const timestamp &tp, const Task &task): tp(tp), task(task), worker() {}

    TaskID &SetWorker(unsigned n) { worker = n; return *this; }
};

class NotificationQueue {
public:
    bool pop(Task &task) {
        lock_t lk(_mutex);

        while (!_done || _finish_queue) {
            if (!_tasks.empty()) {
                auto front = _tasks.begin();
                if (front->first > std::chrono::steady_clock::now()) { // TASK NOT READY
                    _ready.wait_until(lk, front->first);
                }
                else { // TASK READY
                    std::swap(task, front->second);
                    _tasks.erase(front);
                    return true;
                }
            }
            else { // NO TASKS IN "QUEUE"
                _ready.wait(lk, [&](){ return _done; });
                if (_finish_queue && _done && _tasks.empty()) {
                    _finish_queue = false;
                }
            }
        }
        return false;
    }

    bool try_pop(Task &task) {
        lock_t lk(_mutex, std::try_to_lock);
        if (!lk) return false;
        else {
            auto front = _tasks.begin();
            if (front == _tasks.end()) return false;
            timestamp now = std::chrono::steady_clock::now();
            timestamp then = front->first;
            if (then >= now) return false;
            else {
                std::swap(task, front->second);
                _tasks.erase(front);
                return true;
            }
        }
    }

    TaskID push(callback cb, void *args, unsigned millis) {
        timestamp tp = std::chrono::steady_clock::now() + std::chrono::milliseconds(millis);
        Task t{cb, args};
        TaskID result{tp, t};
        {
            lock_t lk(_mutex);
            _tasks.insert(std::make_pair(tp, t));
        }
        _ready.notify_one();
        return result;
    }

    std::pair<bool, TaskID> try_push(callback cb, void *args, unsigned millis) {
        TaskID result{};
        {
            lock_t lk(_mutex, std::try_to_lock);
            if (!lk) return {false, result};
            timestamp tp = std::chrono::steady_clock::now() + std::chrono::milliseconds(millis);
            Task t{cb, args};
            result.tp = tp;
            result.task = t;
            _tasks.insert(std::make_pair(tp, t));
        }
        _ready.notify_one();
        return {true, result};
    }

    bool remove(const TaskID &id) {
        bool result = false;
        {
            lock_t lk(_mutex);
            auto range = _tasks.equal_range(id.tp);
            auto it = range.first;
            while (it != range.second) {
                if (it->second == id.task) {
                    it = _tasks.erase(it);
                    result = true;
                }
                else {
                    ++it;
                }
            }
        }
        if (result) {
            _ready.notify_one();
        }
        return result;
    }

    void done() {
        {
            lock_t lock{_mutex};
            _done = true;
        }
        _ready.notify_one();
    }
private:
    std::multimap<timestamp, Task> _tasks;
    std::mutex _mutex;
    std::condition_variable _ready;
    bool _done{false};
    bool _finish_queue{true};
};

class Scheduler {
public:
    Scheduler() {
        std::cout << "===== constructing Scheduler with " << _count << " workers =====\n";
        for (unsigned n = 0; n != _count; ++n) {
            _workers.emplace_back([&, n]{ run(n); });
        }
    }
    ~Scheduler() {
        for (auto &queue: _q) queue.done();
        for (auto &worker: _workers) worker.join();
    }

    TaskID schedule(callback cb, void *args, unsigned millis) {
        auto i = _index++;

        for (unsigned n = 0; n != _count * 100; ++n) {
            auto pushed = _q[(n + i) % _count].try_push(cb, args, millis);
            if (pushed.first) return pushed.second.SetWorker((n + i) % _count);
        }

        return _q[i].push(cb, args, millis).SetWorker(i);
    }

    bool unschedule(const TaskID &id) {
        return _q[id.worker % _count].remove(id);
    }
private:
    void run(unsigned i) {
        for (;;) { // while (true)
            Task f;
            for (unsigned n = 0; n < _count; ++n) {
                if (_q[(i + n) % _count].try_pop(f)) break;
            }
            if (!f && !_q[i].pop(f)) break;
            f();
        }
    }

    const unsigned _count{std::thread::hardware_concurrency()};
    std::atomic<unsigned> _index{0};

    std::vector<std::thread> _workers;
    std::vector<::NotificationQueue> _q{_count};
};


#endif//SCHEDULER_H
