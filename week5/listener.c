/*
** listener.c -- a datagram sockets "server" demo
** taken from beej
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MYPORT "4950"	// the port users will be connecting to

#define MAXBUFLEN 100

#define THREADS_COUNT 10

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

struct data {
    int id;
    struct sockaddr_storage their_addr;
    char buf[MAXBUFLEN];
};


void *print_data(struct data *information){
    char s[INET6_ADDRSTRLEN];
    printf("Thread # %d: starting\n", information->id);
    printf("Thread # %d: got packet from %s\n", information->id,
			   inet_ntop(information->their_addr.ss_family,
						 get_in_addr((struct sockaddr *)&information->their_addr),
                         s, sizeof s));
    printf("Thread # %d: got massage %s\n", information->id, information->buf);
    printf("Thread # %d: going to sleep\n", information->id);
    sleep(10);
    printf("Thread # %d: goodbye!\n", information->id);
}




int main(void)
{
	int n = THREADS_COUNT;
	int current_thread_count = 0;
	pthread_t threads[THREADS_COUNT];


	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	int numbytes;
	struct sockaddr_storage their_addr;
	char buf[MAXBUFLEN];
	socklen_t addr_len;
	char s[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
							 p->ai_protocol)) == -1) {
			perror("listener: socket");
			continue;
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("listener: bind");
			continue;
		}

		break;
	}

	while (1) {


		if (p == NULL) {
			fprintf(stderr, "listener: failed to bind socket\n");
			return 2;
		}


		printf("listener: waiting to recvfrom...\n");

		addr_len = sizeof their_addr;
		if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
								 (struct sockaddr *)&their_addr, &addr_len)) == -1) {
			perror("recvfrom");
			exit(1);
		}

        buf[numbytes] = '\0';

        struct data *data1 = malloc(sizeof(struct data));

        (*data1).id = current_thread_count++;
        (*data1).their_addr = their_addr;
        memcpy((*data1).buf, buf, numbytes);

		pthread_create(&threads[current_thread_count], NULL, (void *)print_data, (void *)data1);

        if (current_thread_count == THREADS_COUNT){
            break;
        }
	}

	close(sockfd);


	return 0;
}
