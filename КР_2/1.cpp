// путь к директории как аргумент командной строки 
// -> выводит число файлов в данной директории, 
// -> считает число файлов у которых минимум 2 жесткие связи (рекурсивно), 
// -> выводит все вложенные директории(не рекурсивно)

// buf.st.link в stat
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int num_hard_links(struct dirent* ds);
int directory_files_counter(struct dirent*ds, DIR* dirp);
void print_dir(struct dirent*ds, DIR* dirp);

int main(int argc, char* argv[]) 
{
    char path[1000] = {};
    if (argc < 2)
        strcpy(path, "./");
    else 
        strcpy(path, argv[1]);
    
    DIR* dirp = opendir(path);
    struct dirent* ds = readdir(dirp);
    
    int file_number = 0;
    int num_files_hard_links = 0;

    while (ds) 
    {
        file_number = directory_files_counter(ds, dirp); 
        if(num_hard_links(ds) >= 2)
        {
            num_files_hard_links++;
        }

        print_dir(ds, dirp);
    }
    printf("Number of files in current directory: %d\n", file_number - 2);
    printf("Number of files with >2 hard links: %d\n", num_files_hard_links);
    
    closedir(dirp);
    return 0;
}

int directory_files_counter(struct dirent*ds, DIR* dirp)
{
    int file_number = 0;

    // printf("%s\n", ds->d_name);
    file_number++;
    ds = readdir(dirp);

    if(opendir(ds->d_name) != NULL) //если это директория вложенная в текущую
    {
        directory_files_counter(ds, dirp);
        ds = readdir(dirp);
    }
    return file_number;
}

//--------- Определить количество жестких ссылок у файла
int num_hard_links(struct dirent* ds)
{
    struct stat file_info_struct = {};
    stat(ds->d_name, &file_info_struct);

    int number_of_hard_links = file_info_struct.st_nlink;
    return number_of_hard_links;
}

//---------- Вывод вложенных директорий
void print_dir(struct dirent*ds, DIR* dirp)
{
    if(opendir(ds->d_name) != NULL) //если это директория вложенная в текущую
    {
        printf("%s\n",ds->d_name);
        ds = readdir(dirp);
    }
}

