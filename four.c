#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid==0)
    {
        printf("I am child!");
        exit(0);
    }
    else
    {
        wait(NULL);
        
    }
}