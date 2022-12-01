// ls -l

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_ls(struct dirent* ds);

int main(int argc, char* argv[]) 
{

    char path[1000] = {};
    if (argc < 2)
        strcpy(path, "./");
    else 
        strcpy(path, argv[1]);

    DIR* dirp = opendir(path);

    struct dirent* ds = readdir(dirp);
    while (ds) {
        print_ls(ds);
        ds = readdir(dirp);
    }

    closedir(dirp);
    
    return 0;
}

void print_ls(struct dirent* ds)
{
    struct stat file_info_struct = {};
    stat(ds->d_name, &file_info_struct);
         
    printf("%X ", file_info_struct.st_mode);  // режим доступа                 
    printf("%d ", file_info_struct.st_uid); /* идентификатор пользователя-владельца */          
    printf("%d ", file_info_struct.st_gid);  /* идентификатор группы-владельца */                  
    printf("%5ld ", file_info_struct.st_size); /* общий размер в байтах */             
    printf("%s\n", ds->d_name);
}