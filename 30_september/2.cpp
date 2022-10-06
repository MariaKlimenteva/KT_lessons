// написать две проги, которые используют разделенную память

    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    #include <sys/ipc.h>
    #include <sys/stat.h>
    #include <stdio.h>

    int main ()
    {
        umask(0);
        int key = ftok ("1.cpp", 1);
        int ret = shmget(key, sizeof(int)*3, 0777);
        
        if(ret == -1)
        {
            shmget (key, sizeof(int)*3, 0777| IPC_CREAT);
            int *array = (int*)shmat (ret, NULL, 0);
            array[0] = 0;
            array[1] = 0;
            array[2] = 0;
        }
        int *array = (int*)shmat (ret, NULL, 0);
        array[1] += 1;
       
    
        printf("%d %d %d\n", array[0], array[1], array[2]);
        return 0;
    }