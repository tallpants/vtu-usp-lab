/*
 * Write a C/C++ program to emulate the Unix 'ln' command
 */

/*
 * Instructions
 * ==============
 *
 * $ touch f1
 * $ ./q5b f1 f1hard
 * $ ./q5b -s f1 f1soft
 * $ ls -li f1*
 *
 * 2362015 ... f1
 * 2362015 ... f1hard
 * 2362016 ... f1soft -> f1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

int main(int argc, char **argv) {

    if (argc > 4 || argc < 3) {
        printf("\nInvalid input.");
        exit(1);
    }

    if (argc == 4 && strcmp(argv[1], "-s") != 0) {
        printf("\nInvalid input.");
        exit(1);
    }

    if (argc == 3) {
        if (link(argv[1], argv[2]) == -1) {
            printf("\nHard link failed.");
        }
    } else {
        if (symlink(argv[2], argv[3]) == -1) {
            printf("\nSymbolic link failed.");
        }
    }

    return 0;
}