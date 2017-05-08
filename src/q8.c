/**
 * Program to avoid zombie process
 * by forking twice
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  int pid1, pid2;
  pid1 = fork();

  if (pid1 < 0)
  {
    printf("Fork fails");
    exit(0);
  }

  else if (pid1 == 0)
  {
    pid2 = fork();
    if (pid2 < 0)
    {
      printf("fork fails");
      exit(0);
    }

    else if (pid2 == 0)
    {
      sleep(1);
      printf("The PID of parent process is %d", getppid());
      exit(0);
    }

    else if (pid2 > 0)
      exit(0);
  }

  else if (pid1 > 0)
    wait(0);
  
  system("ps -o pid,ppid,stat,cmd");

  return 0;
}