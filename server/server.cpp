#include <iostream>
#include <stdio.h>
#include <sys/types.h>  /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>   //htons
#include <netinet/in.h>  //structs socketaddr_in
#include <strings.h>
#include <unistd.h>
#define PORT 3535
#define BACKLOG 8
#define ERROR -1
#define NUM_CLIENTS 3

using namespace std;




//-----No dependencies
#include "src/animal.cpp"
#include "src/hash.cpp"
#include "src/file_hash.cpp"


//-----Dependencies
#include "src/hash_table.cpp"
#include "src/animal_controller_client.cpp"
#include "src/application_controller.cpp"    //Declare animal
#include "src/test.cpp"                      //Test of application functionalities
#include "src/random.cpp"                    //Use hash_table for show



void check_user_option_main_menu(char request[16]){
    //Insert a pet
    if(request[0] = '1'){
        options_main_menu(1);
    }
    //Show a pet
    else if(request[0] = '2'){
        options_main_menu(2);
    }
    //Delete a pet
    else if(request[0] = '3'){
        options_main_menu(3);
    }
    //Search for a register
    else if(request[0] = '4'){
        options_main_menu(4);
    }
    //Exit 5 option not yet
}

void * function (void *ap){
	char request[16];
    double val= 0;
	int r;
	while(true){
	    cout << "Actions that the user can do ... " << *(int*)ap <<endl << endl;
        r = recv(*(int*)ap, request, 16, 0);
        //Check the option of the user
        check_user_option_main_menu(request);
		printf("Cliente #%d:  %s \n",*(int*)ap,  request);

	}
	close(*(int*)ap);
}



void create_server(){
	int server_code = socket(AF_INET, SOCK_STREAM, 0 );
	int size = sizeof(struct sockaddr);
	char buffer[16];
	pthread_t hilo[3];

	if(server_code == -1){
		cerr << "Error creating the socket" << endl;
	}


	//Now we are going to configure the socket
	struct sockaddr_in  server;
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(server.sin_zero, 8); /*Advise for standar posix */
	int r = bind(server_code, (struct sockaddr *)&server, size);
	if (r == ERROR){
		cerr << "error in binding";
	}
	r = listen(server_code, BACKLOG);
	if (r == ERROR){
		cerr << "error in listening";
	}

	//Now the client
	int client_code;
	struct sockaddr_in  client;
	size_t size_cli;
	cout << "Waiting for a client..." << endl;
	int cont = 0;
	int result;
	int arg =1,c; /*  c -> control variable */

	while(client_code = accept(server_code, (struct sockaddr *)& client, (socklen_t*)&size_cli)){

		int *int_code = new int[0];
		int_code[0] = client_code;

		cout << "The client has connected "<< client_code  << endl;
		if (r == ERROR){
			cerr << "error accepting";
		}
		if(pthread_create(&hilo[cont], NULL,  function, (void*) int_code)!= 0){
			perror("There was an error creating the thread.");
		}
	}

	close(server_code);

}

int main(){
    create_server();
	return 0;
}
