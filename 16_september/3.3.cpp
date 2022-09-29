//Создает 4 процесса, 3 процесса пишут в pipe, последний читает и определяет какой процесс это делает

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

    
int main ()
{
    
    int pipefd[2];
    int MaxLen = 100;
    char str[MaxLen];
    pipe(pipefd);
    pid_t p = fork();
    pid_t q = fork();
    if(p)
    {
        write (pipefd[1], "Hello (send from parent 1 to child 1)", 36);
        int pid_1 = getpid();
        close(pipefd[0]);
        close(pipefd[1]);

    } 
    else
    {
        write (pipefd[1], "Hello (send from parent 1 to child 1)", 36);
        int pid_2 = getpid();
        close(pipefd[0]);
        close(pipefd[1]);


    if(q)
    {
        

    }
        else
        {
            read (pipefd[0], str, MaxLen);
            printf ("%s, pid = %d\n", str, getpid());
            close(pipefd[0]);
            close(pipefd[1]);
        }
        if 
    } 
    return 0;  
}    
