#include<stdio.h>

int main()
{
    int noPro, noRe;
    printf("\nEnter the number of processes");
    scanf("%d", &noPro);
    printf("\nEnter the no of resources");
    scanf("%d", &noRe);
    int need[noPro][noRe];
    int have[noPro][noRe];
    int max[noPro][noRe];
    int allocated[noRe];

    printf("\nEnter the max needed");
    for(int i=0;i<noPro;i++)
    {
        printf("\nEnter the resources needed for %d", i+1);
        for (int j=0;j<noRe;j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the have");
    for(int i=0;i<noPro;i++)
    {
        printf("\nEnter the resources  %d has", i+1);
        for (int j=0;j<noRe;j++)
        {
            scanf("%d", &have[i][j]);
        }
    }

    printf("\nEnter the already allocated");
    for(int i=0;i<noRe;i++)
    {
        scanf("%d", &allocated[i]);
    }
    for(int i=0;i<noPro;i++)
    {
        for (int j=0;j<noRe;j++)
        {
            need[i][j] = max[i][j]-have[i][j];
        }
    }
    int comp[noPro];
    for(int i=0;i<noPro;i++)
        comp[i] = 0;
    int completed = 0;
    int done = 0;
    while(completed<noPro)
    {
        done = 0;
        for(int i=0;i<noPro;i++)
        {
            int canBeAllocated = 1;
            if(comp[i]==0)
            {
                for(int j=0;j<noRe;j++)
                {
                    if(need[i][j]>allocated[j])
                    {
                        canBeAllocated = 0;
                        break;
                    }
                }
            }
            if(canBeAllocated==1 && comp[i]==0)
            {
                done = 1;
                comp[i] = 1;
                printf(" P%d ->", i);
                completed++;
                for(int j=0;j<noRe;j++)
                {
                    allocated[j] += need[i][j];
                }
            }
        }
        if(done==0)
        {
            break;
        }
    }
    if(completed<noPro)
    {
        printf("Not possible");
    }
}