// Синхронизация процессов join
// Семафор - целая неотр переменная s>=0 
// инициализируется s = 0 
// неделимые операции p: (проверять) while (s = 0) block;           probieren
//                                   s--; (процесс разблокируется)  verhogen
//                    v: делает s++;

// Задание: реализовать семафор с помощью разделяемой памяти
// (сделать переменную в разделяемой памяти, две функции, в отдельную библиотеку, в main показать как происходит синхронизация процессов, два файла + хэдер)

// прога которая выполняется полностью, после остановки первой проги 1.2.cpp
// запускается второй
#include "semafor.h"

int main()
{
    int* s;
    printf("I am the second");
    sleep(10);
    verhogen(s);
    printf("+ 1 to semafor, the second programm finished\n");

    return 0;
}