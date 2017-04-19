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


#define PORT 9999  /* This need to be  the same port  of the server part */
#define LOOPBACK "127.0.0.1"
#define ERROR -1
#define ONLY 0 //When there is just one  protocol that supports the socket

using namespace std;

#include "animal.cpp"
#include "client_controller.cpp"


int clientfd;
struct sockaddr_in client;


void main_menu(){
    cout << "\n\tHello User, Welcome to Pet Factory" << endl;
    cout << "\n\t\t This are the options that we offer" << endl;
    cout << "\t1. Insert a register " <<endl;
    cout << "\t2. Show a register " <<endl;
    cout << "\t3. Delete  a register " <<endl;
    cout << "\t4. Search for a register " <<endl;
    cout << "\t5. Salir " <<endl;
    cout << "user-clinica> ";
}

void menu(int opt){
    cout << "Option of the user: " << opt << endl;
    if (opt == 1){
        insert_animal(clientfd);
    }
    else if (opt == 2){
        show_animal(clientfd);
    }
    else if(opt == 3){
        delete_animal(clientfd);
    }else if(opt == 4){
        show_by_name(clientfd);
    } else if( opt == 5){
        cout << "\n BYE USER \n" << endl;
        cout << "\n\t" << "SEE YOU LATER" << endl;
    }
}



void create_client(){
    int r;
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
    bool flag = true;
    while(flag){
        //Display main menu
        main_menu();

        //Option that the user choose
        int opcion;
        cin >> opcion;

        r = send(clientfd, &opcion, sizeof(opcion), 0);
        if (r != sizeof(opcion)){
            //Re send;
            cout << "CLIENT: The option have not been sent completely. \n";
        }

        //Now after request is sent called another menu
        menu(opcion);
        if(opcion == 5){
            flag = false;
        }
    }
    close(clientfd);
}


int main(){
    create_client();
    return 0;
}
