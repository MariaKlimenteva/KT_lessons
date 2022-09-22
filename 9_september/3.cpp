#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ()
{
    pid_t p = fork ();
    if (p != 0) 
        printf ("It's parent process, parent id = %d\n, child id = %d\n", getpid(), getppid());
    if (p == 0) 
        printf ("It's a child process, parent id = %d\n, child id = %d\n", getpid(), getppid());
    
    return 0;
}