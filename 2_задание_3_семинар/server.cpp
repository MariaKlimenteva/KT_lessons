// СЕРВЕР
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
//--------------- Создание сокета
int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
if(socket_fd != -1)
{
    printf("Идентификатор сокета: %d\n", socket_fd);
}
else printf("Error in socket_fd\n");

//--------------- Связывание сокета с некоторым адресом
if(bind(socket_fd, INADDR_ANY, 0) != 0) printf("Error in bind()\n"); 

//--------------- Создание очереди запросов на соединение
int backlog = 3;
if(listen(socket_fd, backlog) != 0) printf("Error in listen\n");    
    accept()
    
    return 0;
}