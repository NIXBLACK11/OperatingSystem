#include<stdio.h>

int main()
{
    int n = 4;
    int at[n], bt[n], rt[n], tat[n], wt[n], ct[n], st[n];
    printf("\nEnter the arrival time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &at[i]);
    }
    printf("\nEnter the burst time:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &bt[i]);
    }
    st[0] = 0;
    for(int i=1;i<n;i++)
    {
        st[i] = st[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++)
    {
        rt[i] = st[i] - at[i];
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("Arrival time    Burst Time      Start Time      Response Time   Completion Time     Turn Around Time    Waiting Time    ");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t    %d\t\t        %d", at[i], bt[i], st[i], rt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}