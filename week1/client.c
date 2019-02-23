//
// Created by Pavel on 07/02/2019.
//

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <zconf.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 2000

int main()
{
    char buffer[10] = "";

    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if (connection_status == -1){
        printf("lol");
    }

    read(network_socket, buffer, 10);
    printf("%s", buffer);

    close(network_socket);

    return 0;
}