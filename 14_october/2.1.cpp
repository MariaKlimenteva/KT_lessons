// Для работы с разд памятью было:
// ftok - получает по пути ключ
// shmget() -

// Для семафоров:
// semget() - возвращает дескриптор массива семафоров. Готовые средства работы с семафорами. (в массиве до 500 семафоров)
// Семафоры создаются массивами

// Было v(s) то же что и a(s,1)           В случае семафоров есть операции: a(s , n)    s+=n;
//      p(s) то жe что и d(s,1)                                             d(s, n) while(s < n) block; s - = m;
//                                                                          z(s) while(s > 0) block;

// системный вызов semop(semid; 2й ;число семаформа из массива - 3й аргумент)
// если semop < 0 -- z
//            > 0 -- a
//            < 0 -- d
// flags = 0;

// В качестве второго аргумента надо передавать массив структур, как структура для каждого из семафоров
// Обращение через точку пример: mystruct[0].semnum = 3;
//                               mystruct[0].sem_op = 8;

// struct sembuf *mystruct;

// Задание: реализовать семафоры из 1 задания через системные вызовы semop

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    umask(0);
    int key = ftok ("2.cpp", 0);
    int ret = semget(key, 1, 0777| IPC_CREAT | IPC_EXCL);
    
    if(ret == -1)
    {
        ret = shmget (key, 1, 0777);
    }

    semop(ret, mystruct, 1);
    mystruct[0].sem_num = 1;
    mysruct[0].sem_flg = NULL;

    printf("I'm the 1st programm\n");
    sleep(10);
    mystruct[0].sem_op = 
}