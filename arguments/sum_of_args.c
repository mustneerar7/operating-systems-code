/* Takes bunch of numbers as arguments and calculate sum. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int sum = 0;
    for (int i = 1; i < argc; ++i)
    {
        int temp = atoi(argv[i]);
        sum += temp;
    }

    printf("sum: %d\n", sum);
    return 0;
}