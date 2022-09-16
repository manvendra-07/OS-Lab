/***
 * Name : Manvendra Singh
 * Reg : 200968146
 * Date : 09/09/22
 * Code : C program to simulate First Come First Serve Scheduling
 ***/
#include<stdio.h>

int main()
{
        int n,bt[5], wt[5], tat[5], i, j;
        float avwt=0, avtat=0;
        printf("Enter total number of processes : ");
        scanf("%d",&n);

        printf("\nEnter Process Burst Time: \n");
        for(i=0;i<n;i++)
        {
                printf("P[%d] : ", i+1);
                scanf("%d", &bt[i]);
        }

        wt[0]=0;
        for(i=1;i<n;i++)
        {
                wt[i]=0;
                for(j=0;j<i;j++)
                        wt[i]+=bt[j];
        }
        printf("\nGantt Chart : \n\n");
        for(int i=1; i<=n; i++)
                printf("\tP[%d]", i);
        printf("\n0");
        for(int i=0; i<n; i++)
        {
                printf("\t%d", (bt[i]+wt[i]));
        }
        printf("\n");
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");


        for(i=0;i<n;i++)
        {
                tat[i]=bt[i]+wt[i];
                avwt+=wt[i];
                avtat+=tat[i];
                printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        }

        avwt/=i;
        avtat/=i;
        printf("\n\nAverage Waiting Time: %.2f",avwt);
        printf("\nAverage Turnaround Time: %.2f",avtat);

        return 0;
}