#include <iostream>
#include <iomanip>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#include <pthread.h>

#include <cstring>
#include <string>

#include "header.h"

int main() {
    // init
    int fd = shm_open(STORAGE_ID, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 10;
    }

    int res = ftruncate(fd, STORAGE_SIZE);
    if (res == -1) {
        perror("ftruncate");
        return 20;
    }

    void *addr = mmap(NULL, STORAGE_SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 30;
    }

    // work goes here
    pthread_spinlock_t *spinlock = (pthread_spinlock_t*)(addr);
    res = pthread_spin_init(spinlock, PTHREAD_PROCESS_SHARED);
    if (res != 0) {
        perror("pthread_spin_init");
        return res;
    }

    unsigned *count = (unsigned*)(spinlock + 1);
    char **pos = (char**)(count + 1);
    pthread_spin_lock(spinlock);
    if (*pos == 0) {
        *pos = (char*)(pos + 1);
    }
    std::cout << *spinlock << '\n';
    std::cout << std::hex << (void*)*pos << '\n';
    pthread_spin_unlock(spinlock);

    // spawn new process here

    std::cout << "type 'end' to stop\n";
    std::string s;
    s.reserve(STORAGE_SIZE);
    while (std::cin >> s) {
        if (s == "end") break;
        s.push_back('\n');

        pthread_spin_lock(spinlock);
        memcpy(*pos, s.c_str(), s.size());
        *pos += s.size();
        *count += s.size();
        pthread_spin_unlock(spinlock);
    }
    pthread_spin_lock(spinlock);
    *count = -1;
    pthread_spin_unlock(spinlock);

    // cleanup
    res = munmap(addr, STORAGE_SIZE);
    if (res == -1) {
        perror("munmap");
        return 40;
    }

    fd = shm_unlink(STORAGE_ID);
    if (fd == -1) {
        perror("unlink");
        return 100;
    }
}
