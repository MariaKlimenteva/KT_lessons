#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{ 
    // printf ("What is your name?");

    FILE *fp = fopen ("input.txt", "a+");

    if (!fp)
    {
       perror("The file did not open\n");
        return 0;
    }

    int id = 0;
    int my_id = getuid();
    printf ("My id is %d\n", my_id);
    char* name = (char*) calloc (100, sizeof (char));

    int arg = fscanf (fp,"%d %s", &id, name);
    while ((arg == 2) && (id != my_id))
    {
        arg = fscanf (fp,"%d %s", &id, name);
    }
    if (id == my_id){
        printf ("Hello, %s", name);       
    }
    else{
        printf("What is your name?\n");
        scanf ("%s", name);
        fprintf (fp, "%d %s\n", my_id, name);
    } 

    free (name);
    return 0;
}