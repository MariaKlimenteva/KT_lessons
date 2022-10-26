// читает и завершается, пишет принято первое сообщение, второе и тп
#include "2.h"

int main()
{
    int key = ftok("2.1.cpp", 1);

    int msgid = msgget(key, 0777|IPC_CREAT);
    struct my_struct msgp;

    while(true)
    {
        msgrcv(msgid, &msgp, 0, 0);
    
        if(msgp.type == 1)
        {
            printf("The message was received\n");
        }

        if(msgp.type == 2)
        {
            printf("I received all messages\n");
            break;
        }
    }
    return 0;
}