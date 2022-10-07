//pthread_create
//pthread_join - главная нить вызывает вторую, главная дет окончания выполнения второй
//второй аргумент - NULL
//pthread_exit - экстренное завершение нити

//В проге счетчик запущенной нити исполнения, прога запускается +1, при запуске второй +1, 
//потом синхронизация нитей, вывод на экран той переменной

#include <pthread.h>
#include <stdio.h>

void* func(void* arg)
{
    (*((int *)arg))++;
}

int main()
{
    int argument = 0;
    pthread_t thread;
    printf("First thread id: %lu\n",pthread_self());
    pthread_create(&thread, (const pthread_attr_t *)NULL, (void *(*) (void *))func, &argument);
    pthread_join(thread, NULL);
    printf("Second thread id: %lu\n", thread);
    return 0;
}

