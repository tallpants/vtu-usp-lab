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
 * setbuf - stream buffering operations
 * =====================================
 * 
 * #include <stdio.h>
 *
 * void setbuf(FILE* stream, char* buf);
 * 
 * Uses the buffer 'buf' as the buffer for the stream 'stream'.
 * If 'buf' is NULL, then 'stream' will be treated as unbuffered.
 */

/*
 * stdout - standard I/O stream
 * ============================
 *
 * #include <stdio.h>
 *
 * extern FILE *stdout;
 *
 * A stream representing the standard output STDOUT
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Streams the string argument to STDOUT one character at a time
void streamCharacters(char*);

int main(void) {
    pid_t pid;

    if ((pid = fork()) == -1) {
        printf("\nError forking\n");
        exit(1);
    } else if (pid == 0)
        streamCharacters("Output from child\n");
    else
        streamCharacters("Output from parent\n");

    return 0;
}

void streamCharacters(char* str) {

    // Set STDOUT to be unbuffered
    extern FILE* stdout;
    setbuf(stdout, NULL);

    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }

}
