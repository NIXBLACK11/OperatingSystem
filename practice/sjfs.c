#include <stdio.h>
#include <limits.h>

int main()
{
    int n = 4;
    int at[n], bt[n], rt[n], tat[n], wt[n], ct[n], st[n];
    
    printf("Enter the arrival time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    
    printf("Enter the burst time:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    int completed[n];
    int currentTime = 0;
    int totalCompleted = 0;

    for (int i = 0; i < n; i++)
    {
        completed[i] = 0;
    }

    while (totalCompleted != n)
    {
        int currentProcess = -1;
        int currentProcessTime = INT_MAX;
        
        for (int i = 0; i < n; i++)
        {
            if (completed[i] == 0 && at[i] <= currentTime && bt[i] < currentProcessTime)
            {
                currentProcess = i;
                currentProcessTime = bt[i];
            }
        }

        if (currentProcess == -1)
        {
            currentTime++;
        }
        else
        {
            totalCompleted++;
            ct[currentProcess] = currentTime + bt[currentProcess];
            rt[currentProcess] = currentTime - at[currentProcess];
            st[currentProcess] = currentTime;
            tat[currentProcess] = ct[currentProcess] - at[currentProcess];
            wt[currentProcess] = tat[currentProcess] - bt[currentProcess];
            currentTime += bt[currentProcess];
            completed[currentProcess] = 1;
        }
    }
    
    printf("Arrival time    Burst Time      Start Time      Response Time   Completion Time     Turn Around Time    Waiting Time    ");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t    %d\t\t        %d", at[i], bt[i], st[i], rt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}