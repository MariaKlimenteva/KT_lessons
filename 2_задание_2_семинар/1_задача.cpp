//написать ls

#include <dirent.h>
#include <string.h>
#include <stdio.h>

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
        printf("%s\n", ds->d_name);
        ds = readdir(dirp);
    }

    closedir(dirp);
    
    return 0;
}