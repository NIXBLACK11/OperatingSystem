#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
    int id1 = fork(), id2 = fork();
    if(id1 > 0 && id2 > 0)
    {
        printf("In first level %d\n", getpid());
    }
    else if(id1 == 0 && id2 > 0)
    {
        printf("In second level %d parent-> %d\n", getpid(), getppid());
    }
    else if(id1 >0&& id2==0)
    {
        printf("In third level %d parent-> %d\n", getpid(), getppid());
    }
    else if(id1==0 && id2==0)
    {
        printf("In third level %d parent-> %d\n", getpid(), getppid());
    }
}