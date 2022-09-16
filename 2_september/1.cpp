#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{ 
    printf ("User Id = %d\n", getuid());
    return 0;
}