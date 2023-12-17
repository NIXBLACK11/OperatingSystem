#include <stdio.h>
#include<limits.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter number of processes: ");
    scanf("%d", &N);
    int AT[N];
    int BT[N];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AT[i], &BT[i]);
    }

    int CT[N], WT[N], TAT[N], RT[N];
    int completed[N];
    int currentTime = 0;
    int totalCompleted = 0;

    for (int i = 0; i < N; i++) {
        completed[i] = 0;
    }

    while (totalCompleted < N) {
        int shortestJob = -1;
        int shortestTime = INT_MAX;

        for (int i = 0; i < N; i++) {
            if (!completed[i] && AT[i] <= currentTime && BT[i] < shortestTime) {
                shortestJob = i;
                shortestTime = BT[i];
            }
        }

        if (shortestJob == -1) {
            currentTime++;
        } else {
            CT[shortestJob] = currentTime + BT[shortestJob];
            WT[shortestJob] = CT[shortestJob] - AT[shortestJob] - BT[shortestJob];
            TAT[shortestJob] = CT[shortestJob] - AT[shortestJob];
            RT[shortestJob] = WT[shortestJob];
            completed[shortestJob] = 1;
            currentTime = CT[shortestJob];
            totalCompleted++;
        }
    }

    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < N; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, AT[i], BT[i], CT[i], WT[i], TAT[i], RT[i]);
    }
    return 0;
}