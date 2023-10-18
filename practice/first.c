#include<stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid==0)
    {
        printf("This is the child process %d of parent %d\n", getpid(), getppid());
    }
    else if(pid>0)
    {
        printf("This is the parent process %d of parent %d\n", getpid(), getppid());
    }
}