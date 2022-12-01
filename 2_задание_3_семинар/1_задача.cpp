
// задачи:
// (1) читает файл, открывает, отображает в память, на экран выводим отображение и синхронизация, можно туда что то дописать 

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("1.txt", O_RDWR, 0777); //файловый дескриптор, если файл успешно создан или открыт
    printf("%d\n", fd);

    int len = lseek(fd, 0, SEEK_END);
    printf("Len = %d\n", len);

    void* ptr = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    if(ptr == MAP_FAILED) printf ("Can't map\n");
    
    char msg[] = "\n\nHello!";
    memcpy((void*)((char*) ptr + len - strlen(msg)), (const void*)msg, strlen(msg));  

    printf("Returned man map = %d\n", munmap(ptr, len));

        
    if(close(fd) == -1)
    {
        printf("Файл не закрылся\n");
    }
    return 0;
}