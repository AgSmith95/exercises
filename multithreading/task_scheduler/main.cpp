#include "scheduler.hpp"

#include <iostream>
#include <cassert>
#include <chrono>
#include <sstream>

using namespace std::chrono;
using namespace std::literals::chrono_literals;


auto get_thread_hash = [](){
    //return std::hash<std::thread::id>()(std::this_thread::get_id()) % 1000;
    //return std::hash<std::thread::id>()(std::this_thread::get_id());
    return std::this_thread::get_id();
};


void hello(void *then) {
    timestamp now = steady_clock::now();
    if (then) {
        auto time = (now - *(timestamp*)then) / 1ms;
        std::stringstream ss;
        ss  << "==> Task " << time << "ms passed; thread_id=" << get_thread_hash() << '\n';
        std::cout << ss.str();
    }
    else {
        std::cout << "empty\n";
    }
}


int main() {
    std::cout << "main thread_id=" << get_thread_hash() << '\n';

    timestamp start = steady_clock::now();
    void *pstart = (void*)&start;

    Scheduler sched;
    TaskID z{sched.schedule(hello, pstart, 1000)};
    sched.schedule(hello, pstart, 500);
    sched.schedule(hello, pstart, 1500);
    sched.schedule(hello, pstart, 700);
    sched.schedule(hello, pstart, 900);

    TaskID x{sched.schedule(hello, pstart, 2200)};
    TaskID y{sched.schedule(hello, pstart, 2500)};
    sched.schedule(hello, pstart, 300);
    sched.schedule(hello, pstart, 0);
    sched.schedule(hello, pstart, 600);

    bool res = sched.unschedule(x);
    assert(res);
    res = sched.unschedule(y);
    assert(res);
    res = sched.unschedule(x);
    assert(!res);

    return 0;
}