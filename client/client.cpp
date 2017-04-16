#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>     /* for inet_addr */
#include <netinet/in.h>     /* for inet_addr */
#include <arpa/inet.h>      /* for inet_addr */
#include <stdio.h>
#include <strings.h>
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>

#define PORT 3535  /* This need to be  the same port  of the server part */
#define LOOPBACK "127.0.0.1"
#define ERROR -1
#define ONLY 0 //When there is just one  protocol that supports the socket

using namespace std;

int main(){
    int clientfd, r;
    struct sockaddr_in client;

    clientfd = socket(AF_INET, SOCK_STREAM, ONLY);
    if(clientfd == ERROR) {
        perror("Woops, there was an error creating the socket...") ;
    }
    client.sin_family = AF_INET;
	client.sin_port = htons(PORT);
	client.sin_addr.s_addr = inet_addr ("127.0.0.1");

    /* THis is use as a padding to make the structure of the same
        size as sockaddr */
    bzero(client.sin_zero, 8); /*Advise for standar posix */

    socklen_t size;
    size = sizeof(client);
    r = connect(clientfd, (struct sockaddr*)&client, size);
    if(r == ERROR){
        perror("Woops, there was an error connecting...");
    }

    int intr =1;
    while(true){

        cout << "\n\tHello User, Welcome to Pet Factory" << endl;
        cout << "\n\t\t This are the options that we offer" << endl;
        cout << "\t1. Insert a register " <<endl;
        cout << "\t2. Show a register " <<endl;
        cout << "\t3. Delete  a register " <<endl;
        cout << "\t4. Search for a register " <<endl;
        cout << "\t5. Salir " <<endl;
        cout << "user-clinica> ";

        vector < char > buffer;
        string name;
        cin >> name;
        for (int i= 0; i<name.size(); i++)
            buffer.push_back(name[i]);

        r = send(clientfd, buffer.data(), buffer.size(), 0);
        if (r != buffer.size()){
            //Re send;
        }

    }
    close(clientfd);


    return 0;
}
