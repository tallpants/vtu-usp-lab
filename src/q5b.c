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

/*
 * link - create a hard link
 * ==========================
 *
 * #include <unistd.h>
 *
 * int link(const char *oldpath, const char *newpath);
 *
 * Creates a new link (hard link) to an existing file.
 * On success, 0 is returned. On error, -1 is returned and errno is set appropriately.
 */

/*
 * symlink - create a symbolic link
 * =================================
 *
 * #include <unistd.h>
 *
 * int symlink(const char *target, const char *linkpath);
 *
 * Creates a symbolic link named 'linkpath' which contains the string  'target'.
 * On success, 0 is returned. On error, -1 is returned and errno is set appropriately.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

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
            perror("\nHard link failed.");
        }
    } else {
        if (symlink(argv[2], argv[3]) == -1) {
            perror("\nSymbolic link failed.");
        }
    }

    return 0;
}