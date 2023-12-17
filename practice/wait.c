#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t p;
    p = fork();
    if(p == 0)
    {
        printf("\nchild process %d of parent %d", getpid(), getppid());
    }
    else if(p>0)
    {
        wait(NULL);
        printf("\nparent process %d", getpid());
    }
    else
    {
        printf("\n not created");
    }
}