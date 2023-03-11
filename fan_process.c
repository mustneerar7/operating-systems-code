/* One parent process spawns multiple child processes. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

  for (int i=0; i <3; ++i){

    pid_t pid = fork();

    if(pid == 0){
      printf("Child process: %d of parent: %d\n", getpid(), getppid());
      exit(0);
    }
    else{
      wait(NULL);
    }
  }

  return 0;
}
