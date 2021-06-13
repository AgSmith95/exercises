#include <iostream>
#include <iomanip>
#include <sys/mman.h>
#include <fcntl.h>

#include <pthread.h>

#include <cstring>

#include "header.h"

int main() {
    int res = 0;

    // init
    int fd = shm_open(STORAGE_ID, O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 10;
    }

    void *addr = mmap(NULL, STORAGE_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 30;
    }

    // work goes here
    pthread_spinlock_t *spinlock = (pthread_spinlock_t*)(addr);
    std::cout << *spinlock << '\n';

    unsigned *count = (unsigned*)(spinlock + 1);
    char **pos = (char**)(count + 1);
    const char* start_pos = (char*)(pos + 1);
    std::cout << std::hex << (void*)start_pos << '\n';
    char buff[STORAGE_SIZE] = {};
    bool print = false;

    while (true) {
        print = false;
        pthread_spin_lock(spinlock);
        if (*count == -1) {
            pthread_spin_unlock(spinlock);
            break;
        }
        else if (*count > 0) {
            print = true;
            memcpy(buff, start_pos, *count);
            *pos -= *count;
            *count = 0;
        }
        pthread_spin_unlock(spinlock);

        if (print) {
            std::cout << buff << '\n';
            memset(buff, 0, STORAGE_SIZE);
        }
    }

    // cleanup
    res = munmap(addr, STORAGE_SIZE);
    if (res == -1) {
        perror("munmap");
        return 40;
    }

//    fd = shm_unlink(STORAGE_ID);
//    if (fd == -1) {
//        perror("unlink");
//        return 100;
//    }
}