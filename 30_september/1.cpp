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
        int ret = shmget(key, sizeof(int)*3, 0777| IPC_CREAT | IPC_EXCL);

        int *array;
        
        if(ret == -1)
        {
            ret = shmget (key, sizeof(char)*3, 0777);
            array = (int*)shmat (ret, NULL, 0);
        }
        else
        {
            array = (int*)shmat (ret, NULL, 0);
            array[0] = 0;
            array[1] = 0;
            array[2] = 0;
        }
        array[0] += 1;
        
        //shmctl(ret, IPC_RMID, NULL);
        printf("%d %d %d\n", array[0], array[1], array[2]);
        return 0;
    }