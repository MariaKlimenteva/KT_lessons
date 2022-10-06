//односторонний чат: два файла, один создает fifo и то что вводится с консоли записывает в него, второй открывает fifo и печатает

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    const char* path = "2.1.fifo";
    mkfifo(path, 0777);

    int fd = open(path, O_WRONLY);
    char* string;
    scanf("%ms", &string);
    write(fd, string, 10000);
    close(fd);

    return 0;
}