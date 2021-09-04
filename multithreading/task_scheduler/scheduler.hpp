#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>
#include <map>

#include "task.hpp"

using namespace std::chrono;
using namespace std::literals::chrono_literals;

using lock_t = std::unique_lock<std::mutex>;
typedef time_point<steady_clock> timestamp;

class Scheduler {
public:
    Scheduler(): _worker([&](){ run(); }) {}
    ~Scheduler() {
        done();
        _worker.join();
    }

    void schedule(callback cb, void *args, unsigned millis) {
        push(cb, args, millis);
    }
private:
    void run() {
        while (true) {
            Task f;
            if (!pop(f)) break;
            f();
        }
    }

    bool pop(Task &task) {
        lock_t lk(_mutex);

        while (_tasks.empty() && !_done) _ready.wait(lk);
        if (_tasks.empty()) return false;

        auto front = _tasks.begin();
        while (front->first > steady_clock::now()) _ready.wait_until(lk, front->first, [&](){
            auto new_front = _tasks.begin();
            if (new_front->first < front->first) {
                front = new_front;
                return false;
            }
            return true;
        });

        task = std::move(front->second);
        _tasks.erase(front);

        return true;
    }

    void push(callback cb, void *args, unsigned millis) {
        {
            lock_t lk(_mutex);
            _tasks.insert(std::make_pair(steady_clock::now() + milliseconds(millis), Task{cb, args}));
        }
        _ready.notify_one();
    }

    void done() {
        lock_t lock{_mutex};
        _done = true;
    }

    std::thread _worker;

    std::multimap<timestamp, Task> _tasks;
    std::mutex _mutex;
    std::condition_variable _ready;
    bool _done{false};
};


#endif//SCHEDULER_H
