//Создает pipe, записывает туда, потом читаем

#include <unistd.h>
#include <stdio.h>

int main ()
{
    int pipefd[2];
    pipe(pipefd);
    char buf1[] = "Hello";
    char buf2[] = " ";
    write(pipefd[1], buf1, 6);
    read(pipefd[0], buf2, 6);
    close(pipefd[0]);
    close(pipefd[1]);
    printf ("%s\n", buf2);
    return 0;
}