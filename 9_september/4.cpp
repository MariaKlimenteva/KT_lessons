#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    pid_t p = fork();
    if (p == 0)
    {
        execvp(argv[1], argv + 1);
    }
    else
    {
        for (int i = 0; i < 500; i++)
        {
            printf("%d\n", i);
        }
    }
    
    return 0;
}