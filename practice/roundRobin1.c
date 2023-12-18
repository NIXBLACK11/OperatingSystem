#include<stdio.h>

int main()
{
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], lt[n];
    printf("\nEnter the arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("\nEnter the burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        lt[i] = bt[i];
    }

    printf("\nEnter the time quantum: ");
    int TQ;
    scanf("%d", &TQ);

    int completed = 0;
    int currentTime = 0;
    int comp[n];
    for (int i = 0; i < n; i++) {
        comp[i] = 0;
    }

    int i = 0; // Initialize i outside the loop

    while (completed < n) {
        if (comp[i] == 0 && at[i] <= currentTime && lt[i] > 0) {
            if (lt[i] <= TQ) {
                currentTime += lt[i];
                lt[i] = 0;
                comp[i] = 1;
                completed++;
                printf("\nProcess %d -> %d", i, currentTime);
            } else {
                currentTime += TQ;
                lt[i] -= TQ;
            }
        }
        if(i==n-1)
            i = 0;
        else if(at[i+1]<=currentTime)
            i++;
        else
            i=0;
        // i = (i + 1) % n; // Update i in a way that ensures it remains within bounds
    }

    return 0;
}
