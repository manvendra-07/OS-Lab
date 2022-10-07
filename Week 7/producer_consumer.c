#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define SHARED 1



void *Producer();
void *Consumer(); 
sem_t empty, full, sm;
int data;



void *Producer()
{
        int produced;
        printf("\nProducer created");
        printf("\nProducer id is %ld\n", pthread_self());
        for(produced=0; produced<10; produced++) {
                sem_wait(&empty);

                sem_wait(&sm);

                data=produced;

                sem_post(&sm);

                sem_post(&full);
                printf("\nProduced: %d",data);
        }
}



void *Consumer()
{
        int consumed, total=0;
        printf("Consumer created.\n");
        printf("Consumer thread ID: %ld\n", pthread_self());
        for(consumed=0; consumed<10; consumed++)
        {
                sem_wait(&full);

                sem_wait(&sm);

                total=total+data;

                sem_post(&sm);

                sem_post(&empty);
                printf("\nConsumed: %d", data);
                printf("\nRunning total (10 iterations) = %d\n", total);
        }
}



int main()
{
        pthread_t ptid, ctid;
        printf("\nMain thread");



       	sem_init(&empty, SHARED, 1);
       	sem_init(&full, SHARED, 0);
        sem_init(&sm, SHARED, 1);



       	pthread_create(&ptid, NULL, Producer, NULL);
        pthread_create(&ctid, NULL, Consumer, NULL);



       	pthread_join(ptid, NULL);
        pthread_join(ctid, NULL);



       	printf("\n");
}