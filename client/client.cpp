/* Libraries*/
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>     /* for inet_addr */
#include <netinet/in.h>     /* for inet_addr */
#include <arpa/inet.h>      /* for inet_addr */
#include <unistd.h>

/* Constants */
#define PORT 9990
#define DIR "127.0.0.1"
#define ERROR -1
#define ONLY 0              /* When there is just one  protocol that supports the socket */
#define CTRLC 2

/* Custom libraries */
using namespace std;
#include "animal.cpp"

/*  Global variables */
int clientfd;               /* File  descriptor client */
struct sockaddr_in client;
struct sigaction sigIntHandler; /*Handler*/
bool flag = true;

void my_handler_signals(int signal){
    printf("\nClient: Caught signal %d \n",signal);
    if (signal == CTRLC){
        printf("Client : Closing the socketfd \n");
        close(clientfd);
        exit(0);
    }
}


void create_client(){
    int res, opcion;

    /* Events client*/
    sigIntHandler.sa_handler = my_handler_signals;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    /* Create the socket  */
    clientfd = socket(AF_INET, SOCK_STREAM, ONLY);
    if(clientfd == ERROR)
        perror("Woops, there was an error creating the socket...") ;

    /*  Necesary data for the request */
    client.sin_family = AF_INET;
	client.sin_port = htons(PORT);
	client.sin_addr.s_addr = inet_addr (DIR);

    /*Advise for standar posix */
    bzero(client.sin_zero, 8);

    /* Connect to the server */
    res = connect(clientfd, (struct sockaddr*)&client, sizeof(client));
    if(res == ERROR)
        perror("Woops, there was an error connecting...");


    while(flag){
        /* Read the option */
        scanf("%d", &opcion);

        /* Send the request to the server */
        res = send(clientfd, &opcion, sizeof(opcion), 0);

        /* Check if the all message was sent */
        if (res != sizeof(opcion))
            printf("CLIENT: The option have not been sent completely. \n");

        /* Condition for exit */
        if(opcion == 5) flag = false;
    }
    close(clientfd);
}


int main(){
    create_client();
    return 0;
}
