#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], tat[n], wt[n], ct[n], st[n], priority[n];

    printf("Enter the arrival time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("Enter the burst time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time initially equals burst time
    }

    printf("Enter the priority:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    int completed[n];
    int currentTime = 0;
    int totalCompleted = 0;

    for (int i = 0; i < n; i++)
    {
        completed[i] = 0;
    }

    while (totalCompleted < n)
    {
        int highestPriorityProcess = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (completed[i] == 0 && at[i] <= currentTime && priority[i] < highestPriority)
            {
                highestPriorityProcess = i;
                highestPriority = priority[i];
            }
        }

        if (highestPriorityProcess == -1)
        {
            currentTime++;
        }
        else
        {
            st[highestPriorityProcess] = currentTime;
            ct[highestPriorityProcess] = currentTime + 1;
            rt[highestPriorityProcess]--;

            if (rt[highestPriorityProcess] == 0) // Process completed
            {
                tat[highestPriorityProcess] = ct[highestPriorityProcess] - at[highestPriorityProcess];
                wt[highestPriorityProcess] = tat[highestPriorityProcess] - bt[highestPriorityProcess];
                completed[highestPriorityProcess] = 1;
                totalCompleted++;
            }
            currentTime++;
        }
    }

    printf("Arrival time    Burst Time      Priority        Start Time      Response Time   Completion Time     Turn Around Time    Waiting Time    ");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t    %d\t\t        %d", at[i], bt[i], priority[i], st[i], rt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
