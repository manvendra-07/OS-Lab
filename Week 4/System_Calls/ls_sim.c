#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
        pid_t pid;
        pid = fork();
        if( pid < 0 ) {
                exit(0);
        }
        else if( pid == 0 ) {
                execlp("/bin/ls","ls",NULL);
        }
        else {

                wait(NULL);
                printf("Child complete");
                exit(0);
        }
        return 0;
}