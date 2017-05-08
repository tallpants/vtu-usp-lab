/*
 * Write a C/C++ program which demonstrates interprocess
 * communication between a reader process and a writer
 * process.
 *
 * Use mkfifo, open, read, write, and close APIs
 */

/*
 * mkfifo - make a FIFO special file (named pipe)
 * ===============================================
 *
 * #include <sys/types.h>
 * #include <sys/stat.h>
 *
 * int mkfifo(const char *pathname, mode_t mode);
 *
 * Makes a FIFO special file with name 'pathname'.
 * 'mode' specifies the FIFO's permissions.
 *
 * Any process can open the FIFO for reading or writing, but it has to be open
 * at both ends simultaneously before you do any input or output operations on it.
 *
 * Opening a FIFO for reading blocks until some other process opens the FIFO for
 * writing and vice-versa.
 */

/*
 * open - open and possibly create a file
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
 * write - write to a file descriptor
 * ===================================
 *
 * #include <unistd.h>
 *
 * ssize_t write(int fd, const void *buf, size_t count);
 *
 * Writes up to 'count' bytes from the buffer pointed to by 'buf' to the file
 * referred to by the file descriptor 'fd'.
 */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

    int fd;

    mkfifo("myfifo", S_IFIFO | S_IRWXU);

    fd = open("myfifo", O_WRONLY);
    write(fd, argv[1], strlen(argv[1]));

    close(fd);
    return 0;

}