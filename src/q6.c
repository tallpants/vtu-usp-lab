/*
 * Write a C/C++ program to illustrate a race condition.
 */

/*
 * A race condition occurs when multiple processes are trying to do
 * something with shared data, and the outcome depends on the order
 * in which the processes run.
 *
 * To avoid a race conditon either the parent or the child must
 * wait for the other to terminate.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void charAtATime(char*);

int main(void) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        printf("\nError forking\n");
        exit(1);
    } else if (pid == 0) {
        charAtATime("Output from child\n");
    } else {
        charAtATime("Output from parent\n");
    }

    return 0;
}

static void charAtATime(char* str) {
    char* ptr;
    int c;

    setbuf(stdout, NULL);

    for(ptr = str; (c = *ptr++) != 0;) {
        putc(c, stdout);
    }
}
