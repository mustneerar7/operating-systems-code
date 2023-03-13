/* Task 1 creates the process of task2 from its binary. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    printf("This is the first program with pid: %d\n", getpid());
    execvp("./task2", argv);
    //exit(0);
}
