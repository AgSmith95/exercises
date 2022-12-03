/**
 * First you start exe built from this file:
 * 		$ linux_shmem_set_bin
 * 		//bin means binary, yes it is that simple
 * 
 * Then you type strings (not very big one) to write them
 * 		in shared memory you've just 
 * 
 * Then you start your getter:
 * 		$ linux_shmem_get_bin
 * 
 * This will open the same shared memory location and
 * 		read from it the strings you produced
 * 
 * You can type more strings and they will be written by
 * 		set_bin and read by get_bin
 */

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
    std::cout << "addr: " << std::hex << addr << '\n';

    // work goes here
    pthread_spinlock_t *spinlock = (pthread_spinlock_t*)(addr);
    res = pthread_spin_init(spinlock, PTHREAD_PROCESS_SHARED);
    if (res != 0) {
        perror("pthread_spin_init");
        return res;
    }

    unsigned *count = (unsigned*)(spinlock + 1);
    char *start_pos = (char*)(count + 1);

    // spawn new process here

    std::cout << "type 'end' to stop\n";
    std::string s;
    s.reserve(STORAGE_SIZE);
    while (std::cin >> s) {
        if (s == "end") break;
        s.push_back('\n');

        pthread_spin_lock(spinlock);
        memcpy(start_pos + *count, s.c_str(), s.size());
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
