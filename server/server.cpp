#include <iostream>
#include <stdio.h>
#include <sys/types.h>  /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>   //htons
#include <netinet/in.h>  //structs socketaddr_in
#include <strings.h>
#include <string>
#include <unistd.h>
#include <map>
#define PORT 9990
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
#include "src/animal_controller.cpp"
#include "src/application_controller.cpp"    //Declare animal
#include "src/test.cpp"                      //Test of application functionalities
#include "src/random.cpp"                    //Use hash_table for show
#include <stdio.h>
#include <stdlib.h>


/*  Global variables */
map < int , string > clients_map;

void check_user_option_main_menu(int request, int socketfd ){
    int r;
    string cadena = "";

    string user = to_string(socketfd);

    //Insert a pet
    if(request == 1){
        cadena += " INSERT ";
        options_main_menu(1, socketfd);
    }
    //Show a pet
    else if(request == 2){
        cadena += " SHOW ";
        options_main_menu(2, socketfd);
    }
    //Delete a pet
    else if(request == 3){
        cadena += " DELETE ";
        options_main_menu(3, socketfd);
    }
    //Search for a register
    else if(request == 4){

        string aux = options_main_menu(4, socketfd);
        //Return the name to search
        cadena +=" SEARCH "+ aux +" ";
    }
    else if(request == 5){
        cadena +=" EXIT ";
    }

    cadena ="date \"+%H:%M:%S %d/%m/%y\" >>log.log && echo \" "+cadena+" " + clients_map[socketfd]+" \" >> log.log";
    system(cadena.c_str());

    //Exit 5 option not yet
}

void * function (void *ap){
	int request;
    bool flag = true;
    double val= 0;
	int r;
    int socketfd =  *(int*)ap; //WOW --> not evident
	while(flag){
	    cout << "\n\n\t\tServer:Waiting for a request ... " << endl;
        while(request <= 0 || request >=6){
            r = recv(socketfd, &request, sizeof(request), 0);
            cout << r;
        }
        cout << request <<endl;
        if(request == 5){
            cout << "Server BYE BYE";
            flag = false;
        }
        check_user_option_main_menu(request, socketfd);
	}
	close(socketfd);
}



void create_server(){
	int server_code = socket(AF_INET, SOCK_STREAM, 0 );
	int size = sizeof(struct sockaddr);
	char buffer[16];
	pthread_t hilo[3];

	if(server_code == -1){
		cerr << "SERVER :: Error creating the socket" << endl;
	}


	//Now we are going to configure the socket
	struct sockaddr_in  server;
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(server.sin_zero, 8); /*Advise for standar posix */
	int r = bind(server_code, (struct sockaddr *)&server, size);
	if (r == ERROR){
		cerr<<"SERVER :: Error in binding\n";
        return;
	}
	r = listen(server_code, BACKLOG);
	if (r == ERROR){
		cerr << "SERVER :: Error in listening\n";
        return;
	}

	//Now the client
	int client_code;
	struct sockaddr_in  client;
	size_t size_cli;
	cout << "\n\t\tServer: Waiting for a client..." << endl;
	int cont = 0;
	int result;
	int arg =1,c; /*  c -> control variable */

	while(client_code = accept(server_code, (struct sockaddr *)& client, (socklen_t*)&size_cli)){

		int *int_code = new int[0];
		int_code[0] = client_code;


        clients_map[client_code] = inet_ntoa(client.sin_addr);
        cout << "\t\t The client " << clients_map[client_code] << " : Has connected\n";

		if (r == ERROR){
			cerr << "SERVER :: Error accepting";
		}
		if(pthread_create(&hilo[cont], NULL,  function, (void*) int_code)!= 0){
			perror("There was an error creating the thread.");
		}
	}

	close(server_code);
}

void load_data(bool from_scratch){
    if(!from_scratch){
        cout << "\t Server: The data has  been read from disk" <<endl;
        data = read_file_hash(); //hash_table
        ll total = 0;
        for(int i=0; i< size_hash_table; i++){
            total += data[i].size();
        }
        LOC = total; //re pos end of the file for insertion
        cout << "\t Server: The number or registers that were readen from disk were: " << (total -1)<< endl;
    }else{
        create_random_data();
        write_hash_table();
    }
}

int main(){
    cout <<" \n ADMIN : REMEMBER THAT THE FILE var/structures.bin must exist. \n";
    bool aux = false;
    load_data(aux);
    create_server();
	return 0;
}
