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

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(at[j]>at[j+1])
            {
                int tempAt, tempBt;
                tempAt = at[j];
                at[j] = at[j+1];
                at[j+1] = tempAt;
                tempBt = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = tempBt;
            }
        }
    }

    st[0] = at[0];
    for(int i=1;i<n;i++)
    {
        st[i] = st[i-1] + bt[i-1];
    }

    for(int i=0;i<n;i++)
    {
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = st[i] - at[i];
    }

    
    printf("Arrival time    Burst Time      Start Time      Response Time   Completion Time     Turn Around Time    Waiting Time    ");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t    %d\t\t        %d", at[i], bt[i], st[i], rt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}