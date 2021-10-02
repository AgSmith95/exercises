#include "scheduler.hpp"

#include <iostream>
#include <cassert>
#include <chrono>

using namespace std::chrono;
using namespace std::literals::chrono_literals;


void hello(void *then) {
    timestamp now = steady_clock::now();
    if (then) {
        std::cout << (now - *(timestamp*)then) / 1ms << "ms passed\n";
    }
    else {
        std::cout << "empty\n";
    }
}


int main() {
    timestamp start = steady_clock::now();
    void *pstart = (void*)&start;

    Scheduler sched;
    sched.schedule(hello, pstart, 1000);
    sched.schedule(hello, pstart, 500);
    sched.schedule(hello, pstart, 1500);

    std::this_thread::sleep_for(1500ms);
    start = steady_clock::now();

    TaskID x = sched.schedule(hello, pstart, 200);
    TaskID y = sched.schedule(hello, pstart, 5);
    sched.schedule(hello, pstart, 0);

    bool res = sched.unschedule(x);
    assert(res);
    res = sched.unschedule(y);
    assert(res);
    res = sched.unschedule(x);
    assert(!res);

    return 0;
}