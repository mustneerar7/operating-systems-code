#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  
  pid_t pid = fork();

  if(pid == 0){
    execl("/bin/touch", "touch", "hello.txt", NULL);
  }
  else {
    execl("/bin/mkdir", "mkdir", "my_folder", NULL);
    wait(NULL);
  }

  return 0;


}
