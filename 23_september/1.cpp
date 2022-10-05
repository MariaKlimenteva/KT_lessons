// Создать именованый pipe м два процесса, в одном что то вводим с клавиатуры, а во втором что то выводим. 
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
    const char* path = "1.fifo";
    mkfifo(path, 0777);

    if (fork())
    {
        int fd = open(path, O_WRONLY);
        write(fd, "Hello", 5);
        close(fd);
    }
    else
    {
        int fd = open (path, O_RDONLY);
        char buf[5];
        int i = read(fd, buf, 5);
        
        printf("%s", buf);
        close(fd);
    }
    return 0;
}