/*
 * Write a C/C++ program that creates a zombie, and then calls system
 * to execute the ps command to verify that the process is a zombie
 */

/*
 * fork - create a child process
 * ==============================
 *
 * #include <unistd.h>
 *
 * pid_t fork(void);
 *
 * Creates a new process by duplicating the calling process. The child
 * process is run in a separate memory space but duplictes the parent's
 * memory space.
 *
 * Returns PID of the child process in the parent, 0 in the child, or
 * -1 on failure to create and errno is set appropriately.
 */

/*
 * system - execute a shell command
 * =================================
 *
 * #include <stdlib.h>
 *
 * int system(const char* command);
 *
 * Uses fork() to create a child process that executes the shell
 * command specified. The shell command's output will be streamed
 * to STDOUT. system() returns after the command has been completed
 */

/*
 * ps - report a snapshot of current processes
 * ============================================
 *
 * -A -- Show all processes (by default only processes associated
 *       with the current terminal are shown).
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Parent PID: %d\n", getppid());
        printf("Child PID: %d\n\n", getpid());
        exit(0);
    } else
        sleep(3);

    printf("PID\tPPID\tStatus\n");
    system("ps -O ppid,stat | grep q7");
    return 0;
}
