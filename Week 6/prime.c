#include <pthread.h>
#include <stdio.h>

int n1, n2;
void* PrimeGenerator(void* param)
{
        for(int x=n1; x<=n2; x++)
        {
                int flag = 1;
                for(int y = 2; y<=x/2; y++)
                {
                        if(x % y == 0)
                        {
                                flag = 0;
                                break;
                        }
                }
                if(flag == 1)
                        printf("%d\t", x);
        }
        printf("\n");
}

int main()
{
        printf("Enter range : ");
        scanf("%d %d", &n1, &n2);
        printf("Main Thread\n");
        pthread_t t1;
        pthread_create(&t1, NULL, &PrimeGenerator, NULL);
        pthread_join(t1, 0);

        return 0;
}