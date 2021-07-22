#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 4096

int main(void){
  int n;
  char buf[BUFFSIZE];

  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      printf("write error");
      exit(1);
    }
  }

  if (n < 0) {
    printf("read error");
    exit(1);
  }

  exit(0);
}
