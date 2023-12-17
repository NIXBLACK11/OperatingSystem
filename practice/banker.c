#include <stdio.h>
# define MAX_PROCESSES 5
#define MAX_RESOURCES 3

// Function to check if a process can be granted resources
int isSafe(int available[], int **max, int **allocation, int **need, int processes, int resources) {
    int work[resources];
    int finish[processes];
    int safeSequence[processes];
    int i, j, count = 0;

    // Initialize finish array with zeros
    for (i = 0; i < processes; i++)
        finish[i] = 0;

    // Initialize work array with available resources
    for (i = 0; i < resources; i++)
        work[i] = available[i];

    while (count < processes) {
        int found = 0;
        for (i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int canBeAllocated = 1;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canBeAllocated = 0;
                        break;
                    }
                }
                if (canBeAllocated) {
                    for (j = 0; j < resources; j++)
                        work[j] += allocation[i][j];
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            break;
    }

    if (count < processes) {
        printf("System is in an unsafe state. Deadlock might occur.\n");
        return 0;
    } else {
        printf("System is in a safe state. Safe sequence is: ");
        for (i = 0; i < processes; i++)
            printf("%d ", safeSequence[i]);
        printf("\n");
        return 1;
    }
}

int main() {
    int processes, resources, i, j;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &processes);

    printf("Enter the number of resources (max %d): ", MAX_RESOURCES);
    scanf("%d", &resources);

    if (processes > MAX_PROCESSES || resources > MAX_RESOURCES) {
        printf("Exceeding the maximum limit of processes or resources.\n");
        return 1;
    }

    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];

    printf("Enter the available resources:\n");
    for (i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    printf("Enter the maximum resources required for each process:\n");
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocated resources for each process:\n");
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

    // Calculate need matrix
    for (i = 0; i < processes; i++)
        for (j = 0; j < resources; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    // Perform safety check
    isSafe(available, max, allocation, need, processes, resources);

    return 0;
}