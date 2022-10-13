#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main ()
{
    int pipe_array[2] = {};
    pipe (pipe_array);
    int first = 0, second = 0;
    pid_t pid = 0;
    char string[3][100] = {};
    first = fork();
    second = fork();
    if (first && second)
    {
        close (pipe_array[1]);
        for (int cnt = 0; cnt < 3; cnt++)
        {
            int length = 0;
            for (read (pipe_array[0], string[cnt], 1); '0' <= string[cnt][0] && string[cnt][0] <= '9'; read (pipe_array[0], string[cnt], 1))
            {
                length *= 10;
                length += string[cnt][0] - '0';
            }
            read (pipe_array[0], string[cnt], length);
        }
        for (int cnt = 0; cnt < 3; cnt++)
        {
            int i = 0;
            for (pid = 0; '0' <= string[cnt][i] && string[cnt][i] <= '9'; i++)
            {
                pid *= 10;
                pid += string[cnt][i] - '0';
            }
            printf ("Sender pid: %d, message: %s", pid, string[cnt] + i);    
        }
        close (pipe_array[0]);
    }
    else
    {
        close (pipe_array[0]);
        pid = getpid();
        sprintf (string[0], "%d", pid);
        if (first)
            strcat (string[0], "I'm second created process\n");
        else if (second)
            strcat (string[0], "I'm first created process\n");
        else
            strcat (string[0], "I'm third created process\n");
        sprintf (string[1], "%d ", strlen (string[0]));
        strcat (string[1], string[0]);
        write (pipe_array[1], string[1], strlen (string[1]));
        close (pipe_array[1]);
    }
    return 0;
}