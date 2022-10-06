// первая прога передает любой текст, чтение, вывод на экран, потом удаление этого сегмента памяти

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    umask(0);
    int key = ftok("3.cpp", 0);
    int ret = shmget(key, sizeof(char)*3, 0777);

    if(ret != -1)
    {
        shmget (key, sizeof(char)*3, 0777| IPC_CREAT);
        char *array = (char*)shmat (ret, NULL, 0);
        char* array = "";
    }
    char* array = "Неllo";
    return 0;
}