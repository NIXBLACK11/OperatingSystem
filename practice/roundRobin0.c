#include<stdio.h>

int main()
{
    int n;
    printf("\nenter the number of processes");
    scanf("%d", &n);
    int at[n];
    int bt[n];
    int lt[n];
    printf("\nenter the at");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &at[i]);
    }
    printf("\nenter the bt");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &bt[i]);
        lt[i] = bt[i];
    }
    printf("\nenter the TQ");
    int TQ=0;
    scanf("%d", &TQ);

    int completed = 0;
    int currentTime = 0;
    int flag = 0;
    int comp[n] ;
    for(int i=0;i<n;i++)
    {
        comp[i] = 0;
    }
    int i = 0;
        for(i=0;completed<n&&i<n;)
        {
            flag = 0;
            if(comp[i]==0 && at[i]>=currentTime && lt[i]<TQ && lt[i]>0)
            {
                currentTime+=lt[i];
                lt[i] = 0;
                flag = 1;
            }
            else if(comp[i]==0 && at[i]>=currentTime && lt[i]>TQ)
            {
                currentTime+=TQ;
                lt[i] -= TQ;
            }
            if(flag == 1 && lt[i]==0)
            {
                completed++;
                comp[i] = 1;
                printf("\nprocess %d -> %d", i, currentTime);
            }
            if(i==n-1)
                i = 0;
            else if(at[i+1]<=currentTime)
                i++;
            else
                i=0;
        }
}