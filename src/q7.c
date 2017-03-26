/*
 * Write a C/C++ program that creates a zombie, and then calls system
 * to execute the ps command to verify that the process is a zombie
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0)
        exit(0);
    else
        sleep(3);

    system("ps -ax");
    return 0;
}
