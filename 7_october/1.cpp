//phtread self - ф-я возвр идентеф текущ нити исполнения, в кот была вызвана данная ф-я
//Прога, выводит на экран номер текущей нити исполнения

#include <pthread.h>
#include <stdio.h>

int main()
{
    printf("%ld\n",pthread_self());
    return 0;
}