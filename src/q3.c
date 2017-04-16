/*
 * Consider the last 100 bytes as a region. Write a C/C++ program to check
 * whether the region is locked or not. If the region is locked, print pid
 * of the process which hs locked it. If the region is not locked, lock the
 * region with an exclusive lock, read the last 50 bytes, and unlock the
 * region.
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int fd;
    char buf[255];

    fd = open(argv[1], O_RDWR);

    if (fd == -1) {
        printf("File cannot be opened.\n");
        exit(1);
    }

    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_END;
    fl.l_start = SEEK_END - 100;
    fl.l_len = 0;
    fl.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        if (fcntl(fd, F_GETLK, &fl) != -1) {
            printf("The file %s is already locked with process PID %d\n",
              argv[1], fl.l_pid);
            exit(0);
      }
    }

    printf("The process with PID %d has locked the file %s\n",
      fl.l_pid, argv[1]);
    lseek(fd, SEEK_END - 50, SEEK_END);

    if (read(fd, buf, 50) == -1) {
        printf("Read failed.\n");
    } else {
        printf("The last 50 bytes are: \n");
        puts(buf);
    }

    printf("Press any key to unlock.\n");
    getchar();

    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        printf("Lock not released.\n");
    } else {
        printf("Region unlocked.\n");
    }

    close(fd);

    return 0;
}
