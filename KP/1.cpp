// Сoздает n процессов, n - аргумент командной строки, 
// все кроме нулевого процесса отсылают сообщение нулевому, он читает эти сообщения и выводит инфу про их получение на экран

#include <stdio.h>
#include "1.h"

int main(int argc, char** argv)
{
    // char* n[0] = argv[1];
    // printf("%s", n[0]);
    // int n = 4;
    int n = atoi(argv[1]);
    // printf("%d", n);
    int p[n];
    for(int i = 0; i < n; i++)
    {
        p[i] = fork();

        int key = ftok("1.cpp", 1);
        int msgid = msgget(key, 0777);
        struct my_struct msgp = {1};
        msgsnd(msgid, &msgp, 0, 0);

        if(p[i] != 0)//то это родительский процесс
        {
            msgrcv(msgid, &msgp, 0, 0, 0);
        
            if(msgp.type == 1)
            {
                printf("The message was received from %d\n", p[i]);
            }
            // if(msgp.type == 2)
            // {
            //     printf("I received all messages\n");
            //     break;
            // }
        }        
        
        msgp.type = 2; //изменили тип сообщения
        msgsnd(msgid, &msgp, 0, 0);
                
        if(p[i] != 0)//то это родительский процесс
        {
            if(msgp.type == 2)
            {
                printf("I received all messages from %d\n", p[i]);
                break;
            }
        }
    }
    return 0;
}