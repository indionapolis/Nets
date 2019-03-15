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
#include <dirent.h>

#include "common.h"
#include "hashmap.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)

typedef struct
{
    int socket_fd;
    struct sockaddr_in client_addr;
} dict_data;


map_t data_hashmap;


/*Server process is running on this port no. Client has to send data to this port no*/
#define SERVER_PORT     2002

#define DEST_PORT            2000
#define SERVER_IP_ADDRESS   "127.0.0.1"

response_msg client_data;

char data_buffer[1024];




int ping(int item, dict_data* data) {
    int comm_socket_fd = data->socket_fd;
    struct sockaddr_in client_addr = data->client_addr;

    printf("SERVER: send ping to %s:%u\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));


    response_msg msg;
    strcpy(msg.string, "ping");

    send(comm_socket_fd, (char *) &msg, sizeof(response_msg), 0);


    memset(data_buffer, 0, sizeof(data_buffer));

    recv(comm_socket_fd, (char *) data_buffer, sizeof(data_buffer), 0);

    /* state Machine state 4*/
    printf("SERVER: recv from client %s:%u\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));


    response_msg *client_data = (response_msg *) data_buffer;

    printf("SERVER: %s\n", client_data->string);



    return 0;

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

    dict_data* value;
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

            value = malloc(sizeof(dict_data));

            value->socket_fd = comm_socket_fd;
            value->client_addr = client_addr;

            char * key = malloc(sizeof(char)*15);

            sprintf(key, "%s:%u", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            hashmap_put(data_hashmap, key, value);


        }

        ping_all(data_hashmap);
    }/*step 10 : wait for new client request again*/
}


void client(){
    int socket_fd = 0;

    struct sockaddr_in dest;

    dest.sin_family = AF_INET;
    dest.sin_port = DEST_PORT;
    struct hostent *host = (struct hostent *)gethostbyname(SERVER_IP_ADDRESS);
    dest.sin_addr = *((struct in_addr *)host->h_addr);


    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    connect(socket_fd, (struct sockaddr *)&dest,sizeof(struct sockaddr));



    while(1) {
        response_msg response;

//        wait for server ping
        recv(socket_fd, (char *)&response, sizeof(response_msg), 0);



        printf("CLIENT: recv from client %s:%u\n",
               inet_ntoa(dest.sin_addr), ntohs(dest.sin_port));

        printf("CLIENT: %s\n", response.string);

        if (strcmp(response.string, "ping") == 0){
            response_msg msg;
            strcpy(msg.string, "pong");

            send(socket_fd, &msg, sizeof(response_msg), 0);
        }else if (strcmp(response.string, "gimme data") == 0){


            DIR *d;
            struct dirent *dir;
            d = opendir("./data");
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {
                    if (dir->d_type == DT_REG){
                        send(socket_fd, &dir->d_name, sizeof(response_msg), 0);
                    }
                }
                closedir(d);
            }
//           end of transfer
            response_msg msg;
            strcpy(msg.string, "/end/");
            send(socket_fd, &msg, sizeof(response_msg), 0);
        } else if (response.string[3] = '\0', strcmp(response.string, "get") == 0) {
            char file[15];
            sscanf(&response.string[4], "%s", file);

            char path[30];
            sprintf(path, "./data/%s", file);
            FILE* f = fopen(path, "r");
            if (f != 0){
                char buf[20];

//              count words in file
                int count = 0;
                while( fscanf(f, "%s", buf) != EOF )
                {
                    count++;
                }


                send(socket_fd, &count, sizeof(int), 0);

//              send file word by word
                fseek(f, 0, SEEK_SET);
                while(fscanf(f, "%s", buf) != EOF)
                {
                    send(socket_fd, buf, sizeof(char)*20, 0);
                }
            }
        }
    }
}

int print_host(int item, dict_data* data){
    printf("has %s:%u\n", inet_ntoa(data->client_addr.sin_addr), ntohs(data->client_addr.sin_port));

    return 0;
}

void print_known_hosts(){
    hashmap_iterate(data_hashmap, print_host, 0);
}

int print_file(int item, dict_data* data){

    int comm_socket_fd = data->socket_fd;
    char *msg = "gimme data";
    send(comm_socket_fd, msg, sizeof(char)*100, 0);


    while (1){
        response_msg response;
        recv(comm_socket_fd, &response, sizeof(response_msg), 0);

        if (strcmp(response.string, "/end/") == 0){
            break;
        }

        printf("%s:%u %s\n", inet_ntoa(data->client_addr.sin_addr),
               ntohs(data->client_addr.sin_port), response.string);
    }

    return 0;
}

void print_known_filess(){
    hashmap_iterate(data_hashmap, print_file, 0);
}

void menu(){
    char str[1024];
    while (1) {
        printf("Enter command (\"help\" for help): ");
        fgets(str, 1024, stdin);

        if (strcmp(str, "help\n") == 0){
            printf("commands:\nls     - list known hosts\n"
                   "ls -f  - list known files\n"
                   "ls -lf - list local files\n"
                   "get [peer ip_address:port] [file name] - get file from known peer\n");
        } else if (strcmp(str, "ls\n") == 0) {
            print_known_hosts();
        } else if (strcmp(str, "ls -f\n") == 0) {
            print_known_filess();
        } else if (str[3] = '\0', strcmp(str, "get") == 0) {
            char address[15];
            char file[15];

            int ch = sscanf(&str[4], "%s %s\n", address, file);
            if (ch != 2){
                printf("format error\n");
                continue;
            }

            dict_data *data;

            ch = hashmap_get(data_hashmap, address, (void**)(&data));
            if (ch == 0){
//              request data transfer
                char msg[30];
                sprintf(msg, "get %s", file);
                send(data->socket_fd, msg, sizeof(char)*30, 0);


//              get number of words
                int count;
                recv(data->socket_fd, &count, sizeof(count), 0);
                printf("MENU: got count: %d\n", count);


//              read word by word
                char path[30];
                sprintf(path, "data/%s", file);
                FILE *f = fopen(path, "w");
                while (count){

                    count--;
                    recv(data->socket_fd, msg, sizeof(char)*20, 0);
                    fprintf(f, "%s ", msg);
                }

                fclose(f);
                printf("MENU: file downloaded successfully\n");

            }

        }

    }

}

int main(int argc, char **argv) {
    pthread_t threads[2];
    pthread_create(&threads[0], NULL, (void *)server, NULL);
    pthread_create(&threads[1], NULL, (void *)client, NULL);
    menu();
    return 0;
}


