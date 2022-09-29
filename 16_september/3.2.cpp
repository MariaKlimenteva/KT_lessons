//Создаем pipe, с помощью fork делаем дочерний процесс, где делаем то же самое

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

    
int main ()
{
    int pipefd[2];
    int MaxLen = 100;
    pipe(pipefd);
    pid_t p = fork();
    if(p)
    {
        write (pipefd[1], "Hello (send from parent to child)", 34);
        printf ("Parent pid: %d\n", getpid());
        close(pipefd[0]);
        close(pipefd[1]);
        return 0;
    } 
    else
    {
        char str[MaxLen];
        read (pipefd[0], str, MaxLen);
        printf ("%s, pid = %d\n", str, getpid());
        close(pipefd[0]);
        close(pipefd[1]);
        return 0;
    }   
}    
