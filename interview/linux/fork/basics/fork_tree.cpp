#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void fork_and_print_pid() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        std::cout << "Child pid #" << getpid() << '\n';
    }
}

int main() {
    std::cout << "Main pid #" << getpid() << '\n';
    fork_and_print_pid();
    fork_and_print_pid();
    fork_and_print_pid();

    wait(nullptr);
}