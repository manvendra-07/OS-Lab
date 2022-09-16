#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int arr[] = {2,3,2,3,4,5,2,231,54,32,12,4,5,1,34};
int odd[15];
int even[15];
int evencount=0, oddcount=0, sumodd=0, sumeven=0;

void split()
{
        for(int i=0; i<15; i++)
        {
                if(arr[i]%2==0)
                {
                        even[evencount]=arr[i];
                        evencount++;
                }
                else
                {
                        odd[oddcount]=arr[i];
                        oddcount++;
                }
        }
}

void* OddSumThread(void* param)
{
        printf("\nOdd Sum Thread\n");
        for(int i=0; i<oddcount; i++)
        {
                sumodd += odd[i];
        }
        printf("Sum of odd numbers: %d\n", sumodd);
}

void* EvenSumThread(void* param)
{
        printf("\nEven Sum Thread\n");
        for(int i=0; i<evencount; i++)
        {
                sumeven += even[i];
        }
        printf("Sum of even numbers: %d\n", sumeven);
}

int main(){
        printf("\nMAIN THREAD\n");

        printf("Array of numbers: ");
        for(int i=0; i<15; i++)
        {
                printf("%d ", arr[i]);
        }

        split();

        pthread_t thread1, thread2;
        pthread_create(&thread1, NULL, &OddSumThread, NULL);
        pthread_create(&thread2, NULL, &EvenSumThread, NULL);
        pthread_join(thread1, 0);
        pthread_join(thread2, 0);
        return 0;
}