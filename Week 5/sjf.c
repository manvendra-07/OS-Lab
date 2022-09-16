/***
 * Name : Manvendra Singh
 * Reg : 200968146
 * Date : 09/09/2022
 * Code : C program to simulate Shortest Job First Algorithm
 ***/
 
#include<stdio.h>

int main()
{
        int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
        float avg_wt,avg_tat;
        printf("Enter number of process: ");
        scanf("%d",&n);

        printf("\nEnter Burst Time: \n");
        for(i=0;i<n;i++)
        {
                printf("P[%d] : ",i+1);
                scanf("%d",&bt[i]);
                p[i]=i+1;
        }


        for(i=0;i<n;i++)
        {
                pos=i;
                for(j=i+1;j<n;j++)
                {
                        if(bt[j]<bt[pos])
                                pos=j;
                }

                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;

                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
        }

        wt[0]=0;
		
        for(i=1;i<n;i++)
        {
                wt[i]=0;
                for(j=0;j<i;j++)
                        wt[i]+=bt[j];

                total+=wt[i];
        }

        avg_wt=(float)total/n;
        total=0;
        printf("\nGantt Chart : \n\n");                                                                                                                                                                                    7,1            4%
        for(int i=1; i<=n; i++)                                                                                                                                                                                            8,0-1          8%
                printf("\tP[%d]", i);                                                                                                                                                                                      9,1           13%
        printf("\n0");                                                                                                                                                                                                     10,1          17%
        for(int i=0; i<n; i++)                                                                                                                                                                                             11,1-8        21%
        {                                                                                                                                                                                                                  12,1-8        26%
                printf("\t%d", (bt[i]+wt[i]));                                                                                                                                                                             13,1-8        30%
        }                                                                                                                                                                                                                  14,1-8        34%
        printf("\n");                                                                                                                                                                                                      15,0-1        39%
        printf("\nProcess\t\tBurst Time\t\tWaiting Time\tTurnaround Time");                                                                                                                                            16,1-8        43%
        for(i=0;i<n;i++)                                                                                                                                                                                                   17,1-8        47%
        {                                                                                                                                                                                                                  18,1-8        52%
                tat[i]=bt[i]+wt[i];                                                                                                                                                                                        19,1-8        56%
                total+=tat[i];                                                                                                                                                                                             20,1-8        60%
                printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);                                                                                                                                       21,1-8        65%
        }                                                                                                                                                                                                                  22,1-8        69%
                                                                                                                                                                                                                           23,0-1        73%
        avg_tat=(float)total/n;                                                                                                                                                                                            24,0-1        78%
        printf("\n\nAverage Waiting Time = %f",avg_wt);                                                                                                                                                                    25,1-8        82%
        printf("\nAverage Turnaround Time = %f\n",avg_tat);                                                                                                                                                                26,1-8        86%
        return 0;                                                                                                                                                                                                          27,1-8        91%
}