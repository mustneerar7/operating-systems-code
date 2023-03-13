#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("This is the second program with pid: %d\n", getpid());
    printf("Message from task 1: %s\n", argv[1]);
}