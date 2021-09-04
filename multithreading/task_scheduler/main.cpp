#include <iostream>

//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <chrono>
//#include <queue>
//using namespace std::chrono;
//using namespace std::literals::chrono_literals;

#include <map>

#include "scheduler.hpp"
#include "task.hpp"


void hello(void *then) {
    timestamp now = steady_clock::now();
    if (then) {
        std::cout << (now - *(timestamp*)then) / 1ms << "ms passed\n";
    }
}


int main() {
    timestamp start = steady_clock::now();
    void *pstart = (void*)&start;

    Scheduler sched;
    sched.schedule(hello, pstart, 1000);
    sched.schedule(hello, pstart, 500);
    sched.schedule(hello, pstart, 1500);

    return 0;
}