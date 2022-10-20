// первая прога передает любой текст, чтение, вывод на экран, потом удаление этого сегмента памяти
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <stdio.h>

const int MAX_STR = 100;

int main()
{
    umask(0);
    int key = ftok ("3.1.cpp", 0);
    int ret = shmget(key, sizeof(char)*MAX_STR, 0777| IPC_CREAT | IPC_EXCL);
    char* mem;
    mem = (char*)shmat (ret, NULL, 0);
    
    for(int i = 0; i < MAX_STR; i++)
    {
        printf("%s", mem + i);
    }
    shmctl(ret, IPC_RMID, NULL);
    return 0;
}
    
   