#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){

  execl("/usr/bin/sort", "sort", "-o","hello.txt", "hello.txt", NULL);
  return 0;
}
