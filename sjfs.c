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

    for(int i=0;i<n;i++)
    {
        completed[i] = 0;
    }

    while(totalCompleted < n)
    {
        int shortestProcess = -1;
        int shortestTime = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(completed[i]==0 && at[i]<=currentTime && bt[i]<shortestTime)
            {
                shortestProcess = i;
                shortestTime = bt[i];
            }
        }

        if(shortestProcess == -1)
        {
            currentTime++;
        }
        else
        {
            st[shortestProcess] = currentTime;
            ct[shortestProcess] = currentTime + bt[shortestProcess];
            rt[shortestProcess] = st[shortestProcess] - at[shortestProcess];
            tat[shortestProcess] = ct[shortestProcess] - at[shortestProcess];
            wt[shortestProcess] = tat[shortestProcess] - bt[shortestProcess];
            totalCompleted++;
            currentTime += bt[shortestProcess];
            completed[shortestProcess] = 1;
        }
    }

    printf("Arrival time    Burst Time      Start Time      Response Time   Completion Time     Turn Around Time    Waiting Time    ");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t    %d\t\t        %d", at[i], bt[i], st[i], rt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}