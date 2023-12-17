#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], tat[n], wt[n], ct[n], st[n];
    
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

    int completed[n];
    int currentTime = 0;
    int totalCompleted = 0;

    for(int i = 0; i < n; i++)
    {
        completed[i] = 0;
    }

    while(totalCompleted < n)
    {
        int shortestProcess = -1;
        int shortestTime = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(completed[i] == 0 && at[i] <= currentTime && rt[i] < shortestTime)
            {
                shortestProcess = i;
                shortestTime = rt[i];
            }
        }

        if(shortestProcess == -1)
        {
            currentTime++;
        }
        else
        {
            st[shortestProcess] = currentTime;
            ct[shortestProcess] = currentTime + 1;
            rt[shortestProcess]--;

            if (rt[shortestProcess] == 0) // Process completed
            {
                tat[shortestProcess] = ct[shortestProcess] - at[shortestProcess];
                wt[shortestProcess] = tat[shortestProcess] - bt[shortestProcess];
                completed[shortestProcess] = 1;
                totalCompleted++;
            }
            currentTime++;
        }
    }

    printf("Arrival time    Burst Time      Start Time      Response Time   Completion Time     Turn Around Time    Waiting Time    ");
    for(int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t    %d\t\t        %d", at[i], bt[i], st[i], rt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}
