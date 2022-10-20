//=============================================================================
#ifndef SEMAFOR_H
#define SEMAFOR_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <stdio.h>

void probieren(int* s)
{
    while(s[0] = 0)
    {

    }
    s[0]--;
}

void verhogen(int* s)
{
    s[0]++;
}

int* create_mem()
{
    umask(0);
    int key = ftok ("1.1.cpp", 1);
    int ret = shmget(key, sizeof(int)*1, 0777| IPC_CREAT | IPC_EXCL);
        
    if(ret == -1)
    {
        ret = shmget (key, sizeof(int)*1, 0777);
    }

    int* s = (int*)shmat (ret, NULL, 0); 
    s[0] = 0;
    return s;
}

#endif //SEMAFOR_h