#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define DEPTH 4

int main () {
    pid_t pid;
    int i;

    std::cout << "My process id = " << getpid() << '\n';
    for (i=1 ; i <= DEPTH ; i++) {
        pid = fork();   // Fork
        if ( pid ) {
            break;      // Don't give the parent a chance to fork again
        }
        std::cout << "Child #" << getpid() << '\n'; // Child can keep going and fork once
    }

    // std::cout << "Test\n";  // everyone prints that
    wait(nullptr);  // Don't let a parent ending first end the tree below
    return 0;
}