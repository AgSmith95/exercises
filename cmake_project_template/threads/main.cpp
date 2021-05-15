#include <iostream>
#include <thread>

int main() {
    std::cout << "Hello World 0! thread #" << std::this_thread::get_id() << '\n';
    std::thread t1([](){ std::cout << "Hello World 1! thread #" << std::this_thread::get_id() << '\n';});
    std::thread t2([](){ std::cout << "Hello World 2! thread #" << std::this_thread::get_id() << '\n';});

    t1.join();
    t2.join();
    return 0;
}