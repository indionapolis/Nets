//Taken from Abhishek Sagar

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include <zconf.h>
#include "common.h"

#define PORT 2000

int main(int argc, char **argv){
    char string[10] = "hell!";

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(server_socket, 1);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, string, strlen(string), 0);

    close(server_socket);
    return 0;
}