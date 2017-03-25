/*
 * Write a C/C++ program which demonstrates interprocess
 * communication between a reader process and a writer
 * process.
 *
 * Use mkfifo, open, read, write, and close APIs
 */

/*
 * Instructions
 * =============
 *
 * $ ./q4_writer Hello
 *
 * [New Terminal]
 * $ ./q4_reader
 *
 * Received: Hello
 */

/*
 * open -- open and possibly create a file
 * ========================================
 *
 * #include <sys/types.h>
 * #include <sys/stat.h>
 * #include <fcntl.h>
 *
 * int open(const char *pathname, mode_t mode);
 *
 * Given a pathname, returns a file descriptor. The access mode can be
 * O_RDONLY, O_WRONLY, or O_RDWR.
 */

/*
 * read -- read from a file descriptor
 * ====================================
 *
 * #include <unistd.h>
 *
 * ssize_t read(int fd, void *buf, size_t count);
 *
 * Attempts to read up to 'count' bytes from the file descriptor 'fd' into the
 * buffer starting at 'buf'.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {

    int fd;
    char buf[100] = "";

    fd = open("myfifo", O_RDONLY);
    read(fd, buf, 100);

    printf("\nReceived: %s\n", buf);

    close(fd);
    return 0;

}