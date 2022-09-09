#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main() 
{
        int n,i;
        printf("Enter the number of elements: \n");
        scanf("%d", &n);
        int a[20];
        printf("\nEnter the elements of the array: \n");
       	for(i=0;i<n;i++)
		{
                scanf("%d", &a[i]);       
		}
		pid_t pid;
		pid = fork();
		if( pid == 0 )
		{       
			printf("Child process: \n");
			int i,j,temp;
			for(i=0;i<n-1;i++) 
			{
				for(j=0;j<n-1-i;j++) 
				{
					if(a[j+1]<a[j]) 
					{
						temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;
						for(i=0;i<n;i++)
						{
							printf("%d\n", a[i]);
						}
					}
				}
			}
		}


		else 
		{
		 	wait(NULL);
			printf("Parent process");
			for(i=0;i<n;i++)
			{
				printf("%d\n", a[i]);
			}
			printf("\n");
		}
}