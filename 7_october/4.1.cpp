#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pthread.h>

void* func(void* arg)
{
    (*((int *)arg))++;
}
    
int main ()
{
    umask(0);
    int key = ftok ("4.cpp", 1);
    int ret = shmget(key, sizeof(int)*5, 0777|IPC_CREAT|IPC_EXCL); //При удачном завершении вызова возвращается идентификатор сегмента shmid, и -1 при ошибке
    // int* array;

    if(ret == -1)// если ошибка и тогда создаем 
    {
        ret = shmget (key, sizeof(char)*5, 0777);
        int* array = (int*)shmat (ret, NULL, 0);
        array[0] = 0;
        array[1] = 0;
        array[2] = 0;
    }
    int* array = (int*)shmat (ret, NULL, 0);
    
    // array[0] += 1;
    // array[1] = 0;
    array[1] += 1;// прибавляем при каждом запуске программы к первому и второму эл-ту массива 1
    printf("%d %d %d ", array[0], array[1], array[2]);

    int argument = 0;
    pthread_t thread;
    // printf("First thread id: %lu\n",pthread_self());
    pthread_create(&thread, (const pthread_attr_t *)NULL, (void *(*) (void *))func, &argument);
    pthread_join(thread, NULL);
    // printf("Second thread id: %lu\n", thread);
    // printf("The number of thread starts: %d\n", argument);

    int argument1 = 0;
    int argument2 = 0;    

    argument1 += 1;
    argument2 = argument;
    
    array[3] = argument1; 
    array[4] = argument2;
    array[5] = argument1 + argument2;
 
    
    printf("%d %d %d\n", array[3], array[4], array[5]);
    return 0;
}