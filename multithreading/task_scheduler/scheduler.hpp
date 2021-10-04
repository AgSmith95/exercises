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
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using lock_t = std::unique_lock<std::mutex>;
using timestamp = std::chrono::time_point<std::chrono::steady_clock>;

// ===== LOGGING =====

std::string getCurrentTimestamp() {
    const auto current_time_point = std::chrono::system_clock::now();
    const auto current_time{std::chrono::system_clock::to_time_t(current_time_point)};
    const auto current_localtime{*std::localtime(&current_time)};
    const auto current_time_since_epoch {current_time_point.time_since_epoch()};
    const auto current_milliseconds {std::chrono::duration_cast<std::chrono::milliseconds>(current_time_since_epoch).count() % 1000};

    std::ostringstream stream;
    stream << std::put_time(&current_localtime, "%T") << "." << std::setw(3) << std::setfill ('0') << current_milliseconds;
    return stream.str();
}

void printAll() {
    std::cout << std::endl; //;'\n';
}
template <typename T, typename... Args>
void printAll(const T& t, Args... args) {
    std::cout << t << ' ';
    printAll(args...);
}
template <typename T, typename... Args>
void log(const T &/*message*/, Args... /*args*/) {} // stub
//void log(const T &message, Args... args) { // real
//    std::cout   //<< getCurrentTimestamp() /*std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) */
//                //<< ' '
//                << message << ' ';
//    printAll(args...);
//}

// ===== LOGGING =====


struct TaskID {
    timestamp tp;
    Task task;
};

class NotificationQueue {
public:
    bool pop(Task &task) {
        lock_t lk(_mutex);

        while (!_done || _finish_queue) {
            if (!_tasks.empty()) {
                auto front = _tasks.begin();
                if (front->first >= std::chrono::steady_clock::now()) { // TASK NOT READY
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
