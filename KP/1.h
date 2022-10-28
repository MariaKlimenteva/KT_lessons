#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
// #include <conio.h>
#include <stdlib.h>

struct my_struct{
    long type;
};