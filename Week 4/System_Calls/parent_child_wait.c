#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
        pid_t p;
        p = fork();
        if(p == 0) {
                printf("Child ID is: %d\n" , getpid());
                printf("Parent ID is: %d\n" , getppid());
        }
        else {
                wait(NULL);
        }
}