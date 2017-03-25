/*
 * Write a C/C++ POSIX compliant program to check the following limits:
 * 1. No. of clock ticks
 * 2. Max no. of child processes
 * 3. Max path length
 * 4. Max no. of characters in a file name
 * 5. Max no. of open files/processes
 */

/*
 * sysconf - get configuration information at run time
 * ====================================================
 *
 * #include <unistd.h>
 *
 * long sysconf(int name);
 *
 * Gets value for configuration option 'name'.
 * Returns -1 if not defined.
 */

/*
 * pathconf - get configuration values for files
 * ==============================================
 *
 * #include <unistd.h>
 *
 * long pathconf(const char *path, int name);
 *
 * Gets value for configuration option 'name' for the filename 'path'.
 * Returns -1 if not defined.
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {

    printf("\nsysconf\n");
    printf("========\n");
    printf("_SC_OPEN_MAX: The maximum number of files that a process can open is %ld\n", sysconf(_SC_OPEN_MAX));
    printf("_SC_CLK_TCK: The number of clock ticks per second is %ld\n", sysconf(_SC_CLK_TCK));
    printf("_SC_CHILD_MAX: The maximum number of child processes is %ld\n", sysconf(_SC_CHILD_MAX));

    printf("\npathconf\n");
    printf("=========\n");
    printf("_PC_NAME_MAX: The maximum length of a filename in directory '/' is %ld\n", pathconf("/", _PC_NAME_MAX));
    printf("_PC_PATH_MAX: The maximum length of a relative pathname when '/' is the current working directory is: %ld\n", pathconf("/", _PC_PATH_MAX));

    return 0;
}