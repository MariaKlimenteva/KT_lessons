// p2p чат
// сервер выдает ip всем клиентам, передача сообщений

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include "sendall.h"

int main()
{
    //--------------- Создание сокета
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd != -1)
    {
        printf("Идентификатор сокета: %d\n", socket_fd);
    }
    else printf("Error in socket_fd\n");

    //--------------- Заполнение структур
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9002);

    //--------------- Связывание сокета с некоторым адресом
    if(bind(socket_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) != 0) printf("Error in bind()\n"); 

    //--------------- Создание очереди запросов на соединение
    int backlog = 1;
    if(listen(socket_fd, backlog) != 0) printf("Error in listen\n");    

    while(1)
    {
        //------------ Создание нового сокета для общения с клиентом 
        int new_sockfd = accept(socket_fd, NULL, NULL);
        if(new_sockfd == -1) printf("Error in accept\n");

        //------------ Чтение полученных сообщений 
        char client_message[1000];
        recv(new_sockfd, &client_message, sizeof(client_message), 0);

        //------------ Отправление прочитанного обратно клиенту
        int transmitted_info = sendall(new_sockfd, client_message, sizeof(client_message), 0);
        if(transmitted_info == -1) printf("Error in send message\n");

    }
    //---------------- Закрываем первый сокет, прекращаем обмен данными
    shutdown(socket_fd, 2); 
    close(socket_fd);

    return 0;
}