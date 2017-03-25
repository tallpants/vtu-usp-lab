/*
 * Write a C/C++ program that outputs the environment variables
 */

/*
 * Each entry in the environ array points to a string of the form "KEY=VALUE".
 *
 * The last entry in environ points to NULL
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    extern char **environ;

    for (i = 0; environ[i] != NULL; i++) {
        printf("\n%s", environ[i]);
    }

    return 0;
}