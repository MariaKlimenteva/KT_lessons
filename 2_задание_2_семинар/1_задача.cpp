#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char** arcv)
{
    DIR* dirp;
    struct dirent *ds;
    dirp = opendir(arcv[1]); //получаем указатель на поток указателя, указывая как аргумент командной строки имя нужной директории
    while(readdir(dirp) != NULL) //пока не достигли последней записи
    {
        printf("%s\n", ds->d_name);
    }
    closedir(dirp);

    return 0;
}