#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();
    if(child_pid==0)
    {
        printf("Child process");
    }
    else
    {
        wait(NULL);
        printf("Parent process");
        printf("CHILD PID%d", child_pid);
    }
}