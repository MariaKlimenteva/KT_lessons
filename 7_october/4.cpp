//Модифицировать задачу с прошлого семинара 1.cpp, где работали с разделяемой памятью, считала число запусков
//Добавить еще в массив переменные 
//5-я переменная - число запусков певрой нити
//6-я - второй
//7-я - сумма 1 и 2 
//Число нитей передается как аргумент из командной строки

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
    int ret = shmget(key, sizeof(int)*3, 0777);
        
    if(ret == -1)
    {
        shmget (key, sizeof(char)*5, 0777| IPC_CREAT);
        int *array = (int*)shmat (ret, NULL, 0);
        array[0] = 0;
        array[1] = 0;
        array[2] = 0;

    }
        int *array = (int*)shmat (ret, NULL, 0);
        array[0] += 1;
        int argument = 0;
        
        for(int i = 3; i < 5; i++)
        {
            pthread_create(array + i, (pthread_attr_t *)NULL, (void *(*) (void *))func, &argument);
            pthread_join(array[i], NULL); 
            printf("id: %lu\n", thread[i]);
        }
        
    printf("%d %d %d\n", array[0], array[1], array[2]);
    return 0;
}