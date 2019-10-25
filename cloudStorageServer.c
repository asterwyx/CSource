#include<stdio.h>
#include<stdlib.h>
#include<string.h>  //strlen
#include<sys/socket.h>
#include<arpa/inet.h>  //inet_addr
#include<netdb.h>
#include<errno.h>

typedef struct sockaddr_in sockaddr_in;

int main(int argc, char *argv[])
{
	int socket_desc;
	sockaddr_in server;
	char *message;
	
	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("不能创建一个socket");
	}
	

	//Initialize IP array
	char ip[20] = {0};
	

	
