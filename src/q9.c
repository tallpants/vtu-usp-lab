/**
 * Program to implement the system function
 */

 /**
  * Running:
  * ========
  * $ bin/q9 ls
  * $ bin/q9 date
  */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void sys(const char* cmdstr);

int main(int argc, char **argv) {

  int i;
  for (i = 1; i < argc; i++) {
    sys(argv[i]);
    printf("\n");
  }

  return 0;
}

void sys(const char* cmdstr) {
  int pid;
  pid = fork();

  if (pid == 0) {
    execl("/bin/bash", "bash", "-c", cmdstr, NULL);
  } else if (pid > 0) {
    wait(0);
  } else {
    printf("Fork failed.\n");
  }
}