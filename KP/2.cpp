// Создает файл, куда записывает полный путь директории, откуда программа запущена
// Удобно сделать с помощью третьей, используя команду pwd

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    umask(0);
    int fp = open ("File.txt", O_WRONLY | O_CREAT, 0777);
    const char *buf  = "Hello";
    write (fp, buf , 5);

    close(fp);
    // execlp(fd, )

    

    return 0;
}