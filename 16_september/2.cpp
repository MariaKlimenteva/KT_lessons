//Читает что записано из файла и выводит на экран
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    umask(0);
    int fp = open ("File.txt", O_RDWR, 0777);

    char message[100];
    read (fp, message , 6);
    printf ("%s\n", message);

    close(fp);
    return 0;
}