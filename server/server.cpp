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

using namespace std;


int main(){

	int server_code = socket(AF_INET, SOCK_STREAM, 0 );
	int size = sizeof(struct sockaddr);
	char buffer[16];

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
	client_code = accept(server_code, (struct sockaddr *)& client, (socklen_t*)&size_cli);
	if (r == ERROR){
		cerr << "error accepting";
	}

	r = recv(client_code, buffer, 16, 0);
	printf("%s", buffer);
	close(client_code);
	close(server_code);


		
	return 0;
}

