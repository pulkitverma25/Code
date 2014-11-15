/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "customSocketUtility.h"

int main(int argc, char* argv[])
{
	int socketFD, newSocketFD, portNo,pid;
	socklen_t clientAddreLen;
	char* selfIP;

	struct sockaddr_in serverAddress, clientAddress;
	if (argc<2) {
		printf("ERROR, no port provided\n");
		exit(1);
	}

	socketFD=socket(AF_INET, SOCK_STREAM, 0);
	if (socketFD<0) 
		printf("ERROR opening socket\n");
	bzero((char *) &serverAddress, sizeof(serverAddress));

	portNo = atoi(argv[1]);
	serverAddress.sin_family=AF_INET;
	serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
	serverAddress.sin_port=htons(portNo);
	
	if (bind(socketFD,(struct sockaddr *)&serverAddress,sizeof(serverAddress)) < 0) 
		printf("ERROR on binding\n");
	
	printf("\nServer running on %s:%s\n",getSelfIPAddr(),argv[1]);

	listen(socketFD,5);

	clientAddreLen=sizeof(clientAddress);

	while(1)
	{
		newSocketFD=accept(socketFD,(struct sockaddr *) &clientAddress,&clientAddreLen);
		if (newSocketFD < 0) 
			printf("ERROR on accept\n");

		if(!strcmp(inet_ntoa(clientAddress.sin_addr),"127.0.0.1"))
			printf("\n\nNew connection established with %s:%d\n",getSelfIPAddr(),ntohs(clientAddress.sin_port));
		else
			printf("\n\nNew connection established with %s:%d\n",inet_ntoa(clientAddress.sin_addr),ntohs(clientAddress.sin_port));

		pid=fork();
		if(pid<0)
			printf("ERROR: New client cannot be connected\n");
		if(pid==0)
		{
			char name[20];
			printf("Assign Name: ");
			scanf("%s",&name);
			char buffer[256];
			int noOfBytes;
			bzero(buffer,256); //The bzero() function shall place 256 zero-valued bytes in the area pointed to by buffer.
			noOfBytes = read(newSocketFD,buffer,255);

			if (noOfBytes < 0) 
				printf("ERROR reading from socket\n");

			printf("\n%s: %s\n",name,buffer);
			noOfBytes = write(newSocketFD,"Message Delivered\n",20);
	
			if (noOfBytes < 0) 
				printf("ERROR writing to socket\n");

			exit(0);
		}
		else
			close(newSocketFD);	
	}

	close(socketFD);
	

	return 0;
}
