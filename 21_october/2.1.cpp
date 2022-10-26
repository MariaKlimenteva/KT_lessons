// Задача 2:
// 2 проги, первая передает hello world второй

#include "2.h"

int main()
{
    int key = ftok("2.1.cpp", 1);
    int msgid = msgget(key, 0777);

    struct my_struct msgp = {1};//присвоили тип сообщения 1
        
    strcpy(msgp.mtext, "Hello");
    msgsnd(msgid, &msgp, sizeof(my_struct) - sizeof(long), 0);

    msgp.type = 2; //изменили тип сообщения
    msgsnd(msgid, &msgp, sizeof(my_struct) - sizeof(long), 0);
    return 0;
}