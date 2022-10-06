
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    const char* path = "2.1.fifo";
    mkfifo(path, 0777);

    int fd = open (path, O_RDONLY);
    char* string;
    int i = read(fd, string, 10000);
    close(fd);
    printf("%s\n", string);

    return 0;
}