#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int arr[] = {1,3,2,43,21,4,2,-54,3,34,-5,-6,23,3,4};
int pos[15];
int sum=0;
void* summationThread(void* param)
{
        printf("Thread performing summation\n");
        for(int i=0; i<15; i++){
                sum += pos[i];
        }
}

void positive()
{
        for(int i=0; i<15; i++)
        {
                if(arr[i]>=0)
                {
                        pos[i]=arr[i];
                }
        }
}

int main(){
        printf("Array of integers: ");
        for(int i=0; i<15; i++){
                printf("%d ", arr[i]);
        }
        positive();

        printf("\nMain thread\n");

        pthread_t thread;
        pthread_create(&thread, NULL, &summationThread, NULL);
        pthread_join(thread,0);
        printf("Sum of non negative integers is: %d\n", sum);
        return 0;
}