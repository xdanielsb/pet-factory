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

#include "animal.cpp"


int clientfd, r;
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
    char  answer[100];
    if (opt == 1){
           //Define the necesary fields for inserting an animal
        char name[32];   
        char type[32];   
        char breed[16];  
        char genre;    
        int32_t age;   
        int32_t height;
        int32_t weight;

        cout << "\n INSERT REGISTER \n";
        cout << " User we are going to ask you for some data, please ingress the data : "<<endl;
        cout << "\n\tName   = "; cin >> name;
        cout << "\n\ttype   = "; cin >> type;
        cout << "\n\tbreed  = "; cin >> breed;
        cout << "\n\tGenre if it is Female write a {F} but if it is Male  write  a {M}\n"; 
        cout << "\n\tgenre  = "; cin >> genre;
        cout << "\n\tage    = "; cin >> age;
        cout << "\n\theight = "; cin >> height;
        cout << "\n\tweight = "; cin >> weight;


        //Instance the animal
        animal a1(name, type, age, breed,height, weight, genre);   

        //animal a1("Zeus", "Lion", 23, "Warrior", 12, 34, 'M');
        
        r = send(clientfd, &a1, sizeof(a1), 0);
        if (r != sizeof(a1)){
            //Re send;
            cout << "The message have not been sent completely. \n";
        }else{
            cout << "The animal has been sent. \n";
        }

        //Now receive the answer of the server about the operation
        r = recv(clientfd, answer, 100, 0);
        cout << endl << endl;
        cout << "Server response: " << answer << endl;

    }
    else if (opt == 2){
        int number_register;
        animal a1;
        cout << "\n SHOW REGISTER \n";
        //Receive the number of clients
        
        r = recv(clientfd, answer, 100, 0);
        
        cout << " Total number of registers is: " << answer;
        cout << " User write the number of the register to see, please" << endl;
        cout << " Number of the register = " ;
        cin >> number_register;
        
        r = send(clientfd, &number_register, sizeof(number_register), 0);
        //Receive the answer of the user  'animal'
        r = recv(clientfd, &a1, sizeof(a1), 0);
        //Show the animal
        show_animal(a1);

    }
    else if(opt == 3){
        //show_hash_table();
        int number_register;
        cout << "\n DELETE REGISTER \n";
        cout << " Number of the register = " ;
    
        cin >> number_register;
        r = send(clientfd, &number_register, sizeof(number_register), 0);

        //Now receive the answer of the server about the operation
        r = recv(clientfd, answer, 100, 0);
        cout << endl << endl;
        cout << "Server response: " << answer << endl;
    }else if(opt == 4){
        string name;
        cout << "\n SHOW ANIMALS BY NAME\n";
    
        cout << " Name of the register = " ; cin >> name;
    
    } 
}



void create_client(){

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
    }
    close(clientfd);
}


int main(){
    create_client();
    return 0;
}
