/* Libraries*/
#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>   //htons
#include <netinet/in.h>  //structs socketaddr_in
#include <unistd.h>


/* Constants */
#define PORT 9990
#define BACKLOG 8
#define ERROR -1
#define NUM_CLIENTS 5
#define CTRLC 2

using namespace std;

/* Custom Libraries */

//-----No dependencies
#include "src/animal.cpp"
#include "src/hash.cpp"
#include "src/file_hash.cpp"

//-----Dependencies
#include "src/hash_table.cpp"
#include "src/animal_controller.cpp"
#include "src/application_controller.cpp"
#include "src/random.cpp"

/*  Global variables */
map < int , string > clients_map;   /* (clientfd, ip_client) */
bool flag = true;                   /* Continue the program? */
int res;                            /* response of the operations */
struct sigaction sigIntHandler;     /* Handler */
int server_code;                    /* Server code */

void check_user_option_main_menu(int request, int socketfd ){
    string cadena = "";

    if(request == 1){           //Insert a pet
        cadena += " INSERT ";
        options_main_menu(1, socketfd);
    }else if(request == 2){     //Show a pet
        cadena += " SHOW ";
        options_main_menu(2, socketfd);
    } else if(request == 3){    //Delete a pet
        cadena += " DELETE ";
        options_main_menu(3, socketfd);
    }else if(request == 4){ //Search for a register
        string aux = options_main_menu(4, socketfd);
        cadena +=" SEARCH "+ aux +" ";
    }

    cadena ="date \"+%H:%M:%S %d/%m/%y\" >>log.log && echo \" "+cadena+" " + clients_map[socketfd]+" \" >> log.log";

}

/*
 * Handler signals
 */
void my_handler_signals(int signal){
    printf("\n Server : Caught signal %d \n",signal);
    if (signal == CTRLC){

        printf("Close the connection with the clients\n");
        for (map<int,string>::iterator it=clients_map.begin(); it!=clients_map.end(); ++it){
            printf("close connection client %d\n", it->first);
            close(it->first);
        }

        printf("Server : Closing the server \n");
        close(server_code);

        exit(0);

    }
}

/*
 * This function load or create the random data
 */
void load_data(bool from_scratch){
    if(!from_scratch){
        printf("\t Server: The data has  been read from disk\n");
        data = read_file_hash(); //hash_table
        long long total = 0;

        /* Count registers */
        for(int i=0; i< size_hash_table; i++)
            total += data[i].size();

        /* Pointer last register*/
        LOC = total;
        total --;
        printf("\t Server: The number or registers that were readen from disk were: %lld\n",total);
    }else{
        create_random_data();
        write_hash_table();
    }
}

/*
 * This function hold receive the request of the clients
 */
void * hold_client (void *ap){
    int option;
    int socketfd =  *(int*)ap;

	while(flag){
	    cout << "\tServer: Waiting for a request ... \n";
        res = recv(socketfd, &option, sizeof(option), 0);

        printf("Client %d: send the option: %d", socketfd, option);
        /* This is in case of garbage close that connection */
        if(option >= 5 || option <= 0) {
            printf("\nClose client %d \n", socketfd);
            close(socketfd);
            flag = false;
            break;
        }else{
            check_user_option_main_menu(option, socketfd);
        }
	}
    printf("\nClose client %d \n", socketfd);
	close(socketfd);
}

/*
 * This function is responsible for create the server
 * and receive the  connections
 */
void create_server(){

    /* Events Server signals*/
    sigIntHandler.sa_handler = my_handler_signals;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);


    /* Variables for the server */
	server_code = socket(AF_INET, SOCK_STREAM, 0 );
	char buffer[16];
	pthread_t hilo[3];

    /* Variables for the client */
	int client_code;
	struct sockaddr_in  client;
	size_t size_cli;
    int cont_client = 0;

    /*Check the socket initalization */
	if(server_code == ERROR) perror("SERVER :: Error creating the socket\n");


	/* Socket configuration */
	struct sockaddr_in  server;
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(server.sin_zero, 8);

    /* Binding */
	res = bind(server_code, (struct sockaddr *)&server, sizeof(sockaddr));
	if (res == ERROR){
        perror("SERVER :: Error in binding\n");
        close(server_code);
    }
    /* Listening */
	res = listen(server_code, BACKLOG);
	if (res == ERROR) perror("SERVER :: Error in listening\n");


	printf("\n SERVER:: Waiting for a client...\n");

	while( cont_client < NUM_CLIENTS){
        //Capturing the code of the client
        client_code = accept(server_code, (struct sockaddr *)& client, (socklen_t*)&size_cli);

        if(client_code < 0) {
            close(client_code);
            continue;
        }

        //Save the ip of the client of a map
        clients_map[client_code] = inet_ntoa(client.sin_addr);
        cout << " The client " << clients_map[client_code] << " : Has connected\n";

		if (res == ERROR) cerr << "SERVER :: Error accepting";

		if(pthread_create(&hilo[cont_client++], NULL,  hold_client, (void*) &client_code)!= 0){
			perror("There was an error creating the thread.");
		}
	}

	close(server_code);
}



int main(){
    /*    printf("\nADMIN : REMEMBER THAT THE FILE var/structures.bin must exist. \n");*/
    bool load_data_from_scratch = false;
    load_data(load_data_from_scratch );
    create_server();
	return 0;
}
