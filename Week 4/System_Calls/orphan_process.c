#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
        int pid = fork();
        if( pid <0 ) {
                printf("Error");
        }
        else if ( pid == 0 ) {
                printf("Child process\n");
                printf("Parent ID: %d\n" , getppid());
                sleep(5);
                printf("Child orphaned\n");
                printf("Parent PID: %d\n" , getppid());
        }
        else {
                printf("in parent process\n");
        }
        return 0;
}