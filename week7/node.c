//
// Created by Pavel on 2019-03-08.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include <zconf.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "common.h"
#include "hashmap.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)

typedef struct data_struct_s
{
    int socket_fd;
    struct sockaddr_in client_addr;
} data_struct_t;


map_t data_hashmap;


/*Server process is running on this port no. Client has to send data to this port no*/
#define SERVER_PORT     2001

#define DEST_PORT            2000
#define SERVER_IP_ADDRESS   "127.0.0.1"

test_struct_t client_data;
test_struct_t test_struct;

result_struct_t res_struct;
char data_buffer[1024];




void ping(int item, data_struct_t* data) {
    int comm_socket_fd = data->socket_fd;
    struct sockaddr_in client_addr = data->client_addr;

    printf("SERVER: send ping to %s:%u\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    int addr_len = sizeof(struct sockaddr);



    result_struct_t result;
    strcpy(result.string, "ping");


    sendto(comm_socket_fd, (char *) &result, sizeof(result_struct_t), 0,
           (struct sockaddr *) &client_addr, sizeof(struct sockaddr));



    memset(data_buffer, 0, sizeof(data_buffer));

    recvfrom(comm_socket_fd, (char *) data_buffer, sizeof(data_buffer), 0,
             (struct sockaddr *) &client_addr, (socklen_t *) &addr_len);

    /* state Machine state 4*/
    printf("SERVER: recv from client %s:%u\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));


    test_struct_t *client_data = (test_struct_t *) data_buffer;

    printf("SERVER: %s\n", client_data->string);




    sleep(1);

}

void ping_all(map_t hashmap){

    printf("\nSERVER: ready to send ping to nodes\n");

    hashmap_iterate(hashmap, ping, 0);
}


void server(){

    int master_sock_tcp_fd = 0,
            addr_len = 0,
            opt = 1;


    int comm_socket_fd = 0;

    fd_set readfds;

    struct sockaddr_in server_addr,
            client_addr;

    data_struct_t* value;
    data_hashmap = hashmap_new();

    master_sock_tcp_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    server_addr.sin_family = AF_INET;/*This socket will process only ipv4 network packets*/
    server_addr.sin_port = SERVER_PORT;/*Server will process any data arriving on port no 2000*/
    server_addr.sin_addr.s_addr = INADDR_ANY;

    addr_len = sizeof(struct sockaddr);


    bind(master_sock_tcp_fd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr));

    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    if (getsockname(master_sock_tcp_fd, (struct sockaddr *)&sin, &len) == -1)
        perror("getsockname");
    else
        printf("SERVER: port number %d\n", ntohs(sin.sin_port));



    listen(master_sock_tcp_fd, 10);


    while (1) {

        /*Step 5 : initialze and dill readfds*/
        FD_ZERO(&readfds);                     /* Initialize the file descriptor set*/
        FD_SET(master_sock_tcp_fd, &readfds);  /*Add the socket to this set on which our server is running*/

        printf("\nSERVER: blocked on select System call... waits for connection\n\n");




        /*Call the select system call, server process blocks here. Linux OS keeps this process blocked untill the data arrives on any of the file Drscriptors in the 'readfds' set*/
        select(master_sock_tcp_fd + 1, &readfds, NULL, NULL, NULL);

        /*Some data on some fd present in set has arrived, Now check on which File descriptor the data arrives, and process accordingly*/
        if (FD_ISSET(master_sock_tcp_fd, &readfds)) {
            /*Data arrives on Master socket only when new client connects with the server (that is, 'connect' call is invoked on client side)*/
            printf("SERVER: New connection received, accept the connection. \nSERVER: Client and Server completes TCP-3 way handshake at this point\n");


            comm_socket_fd = accept(master_sock_tcp_fd, (struct sockaddr *) &client_addr, (socklen_t *) &addr_len);


            printf("SERVER: Connection accepted from node : %s:%u\n",
                   inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

//          add to hash map

            value = malloc(sizeof(data_struct_t));

            value->socket_fd = comm_socket_fd;
            value->client_addr = client_addr;

            char * key = malloc(sizeof(char)*15);

            sprintf(key, "%s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            hashmap_put(data_hashmap, key, value);


        }

        ping_all(data_hashmap);
    }/*step 10 : wait for new client request again*/
}


void client(){
    sleep(3);
    int sockfd = 0, sent_recv_bytes = 0;

    int addr_len = 0;

    addr_len = sizeof(struct sockaddr);


    struct sockaddr_in dest;

    dest.sin_family = AF_INET;
    dest.sin_port = DEST_PORT;
    struct hostent *host = (struct hostent *)gethostbyname(SERVER_IP_ADDRESS);
    dest.sin_addr = *((struct in_addr *)host->h_addr);


    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    connect(sockfd, (struct sockaddr *)&dest,sizeof(struct sockaddr));



    while(1) {
        result_struct_t result;

//        wait for server ping
        recvfrom(sockfd, (char *)&result, sizeof(result_struct_t), 0,
                 (struct sockaddr *)&dest, (socklen_t *) &addr_len);



        printf("CLIENT: recv from client %s:%u\n",
               inet_ntoa(dest.sin_addr), ntohs(dest.sin_port));

        printf("CLIENT: %s\n", result.string);



//        send response

        result_struct_t msg;
        strcpy(msg.string, "pong");

        sendto(sockfd,
             &msg,
             sizeof(test_struct_t),
             0,
             (struct sockaddr *)&dest,
             sizeof(struct sockaddr));


    }

}

int main(int argc, char **argv) {
    pthread_t threads[1];
    pthread_create(&threads[0], NULL, (void *)client, NULL);
    server();
    return 0;
}


