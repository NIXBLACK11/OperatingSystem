// demonstration of fork system call

// ppid pid

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    fork();
    printf("Happy1\n"); //-->2
    // wait(NULL);
    fork();
    printf("Happy2\n"); //-->4
    // wait(NULL);
    fork();
    printf("Happy3\n"); //-->8
}