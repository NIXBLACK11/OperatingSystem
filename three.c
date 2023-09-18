#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int even_sum = 0, odd_sum = 0;
    pid_t child_pid;

    // Create a child process
    child_pid = fork();
    if(child_pid==0)
    {
        printf("Child process");
    }
    else
    {
        // wait(NULL);
        printf("Parent process");
        printf("CHILD PID%d", child_pid);
    }
}