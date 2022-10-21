// Задача 1:
// 1 прога отсылает 5 пустых сообщений второй, 2 прога читает и завершается, пишет принято первое сообщение, второе и тп

#include "1.h"

int main()
{
    int key = ftok("1.1.cpp", 1);
    int msgid = msgget(key, 0777);

    struct my_struct msgp = {1};
    for(int i = 1; i <= 5; i++)
    {
        msgsnd(msgid, &msgp, 0, 0);
    }
    msgp.type = 2; //изменили тип сообщения
    msgsnd(msgid, &msgp, 0, 0);
    return 0;
}