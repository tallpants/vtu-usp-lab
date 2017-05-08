/**
 * Program to set up a real-time clock interval timer
 * using alarm API
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void printthis();

int main(void) {

  int i = 1;
  struct sigaction act;
  act.sa_handler = printthis;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  sigaction(SIGALRM, &act, 0);

  while (i) {
    alarm(3);
    pause();
    printf("Press 1 to continue, 0 to exit: ");
    scanf("%d", &i);
  }
  
  return 0;
}

void printthis() {
  printf("Finished.\n");
}