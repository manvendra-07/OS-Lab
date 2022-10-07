#include<stdio.h>
#include<stdlib.h>



void print(int x[][10], int n, int m)
{
        int i,j;
        for(i=0; i<n; i++)
	{
                printf("\n");
                for(j=0; j<m; j++){
                        printf("%d\t",x[i][j]);
                }
        }
}



void res_request(int A[10][10], int N[10][10], int AV[10][10], int pid, int m)
{
        int reqmat[1][10];
        int i;
        printf("\nEnter request vector: \n");
        for(i=0; i<m; i++)
	{
                printf("Request for resource %d: ", i+1);
                scanf("%d", &reqmat[0][i]);
        }



       for(i=0; i<m; i++)
                if(reqmat[0][i] > N[pid][i])
		{
                        printf("\nError encountered.\n");
                        exit(0);
                }



       for(i=0; i<m; i++)
                if(reqmat[0][i] > AV[0][i])
		{
                        printf("\nResources unavailable.\n");
                        exit(0);
                }



       for(i=0; i<m; i++)
	{
                AV[0][i]-=reqmat[0][i];
                A[pid][i]+=reqmat[0][i];
                N[pid][i]-=reqmat[0][i];
        }
}



int safety(int A[][10], int N[][10], int AV[1][10], int n, int m, int a[])
{

       int i, j, k, x=0;
        int F[10], W[1][10];
        int pflag=0, flag=0;
        for(i=0; i<n; i++)
                F[i]=0;
        for(i=0; i<m; i++)
                W[0][i]=AV[0][i];



       for(k=0; k<n; k++)
	{
                for(i=0; i<n; i++)
		{
                        if(F[i] == 0)
			{
                                flag=0;
                                for(j=0; j<m; j++)
				{
                                        if(N[i][j] > W[0][j])
                                                flag=1;
                                }
                                if(flag == 0 && F[i] == 0)
				{
                                        for(j=0; j<m; j++)
                                                W[0][j]+=A[i][j];
                                        F[i]=1;
                                        pflag++;
                                        a[x++]=i;
                                }
                        }
                }
                if(pflag == n)
                        return 1;
        }
        return 0;
}




void accept(int A[][10], int N[][10], int M[10][10], int W[1][10], int *n, int *m)
{
        int i, j;
        printf("\nEnter number of processes: ");
        scanf("%d", n);
        printf("\nEnter number of resources: ");
        scanf("%d", m);



       for(i=0; i<*n; i++)
	{
                printf("\nProcess P%d\n", i);
		printf("Allocation : \n");
                for(j=0; j<*m; j++)
                        scanf("%d", &A[i][j]);
		for(j=0; j<*m; j++)
                        scanf("%d", &M[i][j]);
        }



       	printf("\n Available resources: \n");
        for(i=0; i<*m; i++)
	{
                printf(" Resource %d: ", i+1);
                scanf("%d", &W[0][i]);
        }



       for(i=0; i<*n; i++)
                for(j=0; j<*m; j++)
                        N[i][j]=M[i][j]-A[i][j];



       printf("\nAllocation Matrix");
        print(A, *n, *m);
        printf("\nMax Matrix");
        print(M, *n, *m);
        printf("\nNeed Matrix");
        print(N, *n, *m);
        printf("\n");



}



int banker(int A[][10], int N[][10], int W[1][10], int n, int m)
{
        int j, i, a[10];
        j = safety(A, N, W, n, m, a);



       	if(j != 0 )
	{
                printf("\nSystem is SAFE!");
                printf("\nSafe sequence: < ");
                for(i=0; i<n; i++)
                        printf("P%d ", a[i]);
                printf(">\n");
                return 1;
        }
	else
	{
                printf("\nSystem is UNSAFE!\n");
                return 0;
        }
}

int main()
{
        int ret;
        int A[10][10];
        int M[10][10];
        int N[10][10];
        int W[1][10];
        int n, m, pid, ch;



       printf("Banker's Algorithm\n");



       accept(A, N, M, W, &n, &m);
        ret=banker(A, N, W, n, m);



       if(ret !=0 )
	{
		do
		{
                	printf("\nAdditional request? (1=Yes|0=No) ");
                	scanf("%d", &ch);
                        printf("\nEnter PID: ");
                        scanf("%d", &pid);
                        res_request(A, N, W, pid, m);
                        ret=banker(A, N, W, n, m);
                        if(ret == 0 )
                                exit(0);
                }while(ch == 1)
        }
	else
                exit(0);
        return 0;
}