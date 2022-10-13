// первая прога передает любой текст, чтение, вывод на экран, потом удаление этого сегмента памяти
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

const int MAX_STR = 100;

int main()
{
    umask(0);
    int key = ftok ("3.1.cpp", 0);
    int ret = shmget(key, sizeof(char)*MAX_STR, 0777| IPC_CREAT | IPC_EXCL);
    char* message[MAX_STR];

    // int ret = shmget (key, sizeof(char)*100, 0777); 
    char* mem = (char*)shmat (ret, NULL, 0);

    for(int i = 0; i < MAX_STR; i++)
    {
        scanf("%ms", message + i);
    }

    strcpy(*message, mem);
    return 0;
}

// ftok
// Функция shmat подстыковывает сегмент разделяемой памяти shmid к адресному пространству вызывающего процесса. Адрес подстыковываемого сегмента определяется shmaddr с помощью одного из перечисленных ниже критериев:
// Если shmaddr равен NULL, то система выбирает для подстыкованного сегмента подходящий (неиспользованный) адрес.

// Функция shmdt отстыковывает сегмент разделяемой памяти, находящийся по адресу shmaddr, от адресного пространства вызвающего процесса. 