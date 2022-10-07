//Пять нитей исполнения

#include <pthread.h>
#include <stdio.h>

void* func(void* arg)
{
    (*((int *)arg))++;
}

int main()
{
    int argument = 0;
    pthread_t thread[5];
    printf("First thread id: %lu\n",pthread_self());
    
    for(int i = 1; i < 5; i++)
    {
       pthread_create(thread + i, (pthread_attr_t *)NULL, (void *(*) (void *))func, &argument);
       pthread_join(thread[i], NULL); 
       printf("id: %lu\n", thread[i]);
    }
    


    return 0;
}