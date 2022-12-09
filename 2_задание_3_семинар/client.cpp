#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

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

    //--------------- Установка соединения со стороны клиента
    if(connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) printf("Error in connecting\n");

    //--------------- Создание сообщения от клиента, которое будет отправлено серверу
    char message[44] = "This message was send from client to server!";

    return 0;
}
