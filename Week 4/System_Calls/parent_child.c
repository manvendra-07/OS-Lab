#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
        int pid;
        printf("PPID of process is: %d\n", getppid());
        printf("PID of process is: %d\n", getpid());
        fork();
        pid = getpid();
        printf("ID of the child process is: %d\n", pid);
        printf("The parent ID of the child process is: %d\n", getppid());
        return 0;
}