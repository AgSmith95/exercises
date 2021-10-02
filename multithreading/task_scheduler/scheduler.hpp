#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "task.hpp"

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <queue>
#include <map>
#include <algorithm>

using lock_t = std::unique_lock<std::mutex>;
using timestamp = std::chrono::time_point<std::chrono::steady_clock>;


struct TaskID {
    timestamp tp;
    Task task;
};

class NotificationQueue {
public:
    bool pop(Task &task) {
        lock_t lk(_mutex);

        while (_tasks.empty() && !_done) _ready.wait(lk);
        if (_tasks.empty()) return false;

        auto front = _tasks.begin();
        while (front->first > std::chrono::steady_clock::now()) {
            _ready.wait_until(lk, front->first, [&]() {
                auto new_front = _tasks.begin();
                if (new_front == _tasks.end()) {
                    return false;
                }
                if (new_front->first < front->first) {
                    front = new_front;
                    return false;
                }
                return true;
            });
            if (_tasks.empty()) {
                _ready.wait(lk, [&]() { return _tasks.empty(); });
                front = _tasks.begin();
            }
        }

        task = std::move(front->second);
        _tasks.erase(front);

        return true;
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

    bool remove(const TaskID &id) {
        bool result = false;
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
        return result;
    }

    void done() {
        lock_t lock{_mutex};
        _done = true;
    }
private:
    std::multimap<timestamp, Task> _tasks;
    std::mutex _mutex;
    std::condition_variable _ready;
    bool _done{false};
};

class Scheduler {
public:
    Scheduler(): _worker([&](){ run(); }) {}
    ~Scheduler() {
        _q.done();
        _worker.join();
    }

    TaskID schedule(callback cb, void *args, unsigned millis) {
        return _q.push(cb, args, millis);
    }

    bool unschedule(const TaskID &id) {
        return _q.remove(id);
    }
private:
    void run() {
        for (;;) { // while (true)
            Task f;
            if (!_q.pop(f)) break;
            f();
        }
    }

    const unsigned _count{std::thread::hardware_concurrency()};
    std::atomic<unsigned> _index{0};

    std::thread _worker;
    ::NotificationQueue _q;
};


#endif//SCHEDULER_H
