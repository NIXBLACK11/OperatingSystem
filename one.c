// wap to demonstrate parent child relationship where parent compute the sum of even no and child compute sum of odd no

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

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // Child process: Compute sum of odd numbers
        for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
            if (numbers[i] % 2 != 0) {
                odd_sum += numbers[i];
            }
        }
        printf("Child process: Sum of odd numbers: %d\n", odd_sum);
    } else {
        // Parent process: Compute sum of even numbers
        for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
            if (numbers[i] % 2 == 0) {
                even_sum += numbers[i];
            }
        }
        wait(NULL);
        printf("Parent process: Sum of even numbers: %d\n", even_sum);
        
        // Wait for the child process to finish
    }

    return 0;
}
