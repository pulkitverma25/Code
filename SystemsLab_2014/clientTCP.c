/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <arpa/inet.h>
#include "customSocketUtility.h"

int main(int argc, char *argv[])
{
	int socketFD, portNo, n;
	struct sockaddr_in serverAddress;
	struct hostent *server;
	
	char buffer[256];
	if (argc < 3) {
		printf("Enter: %s hostname port\n", argv[0]);
		exit(0);
	}
	portNo = atoi(argv[2]);
	socketFD = socket(AF_INET, SOCK_STREAM, 0);

	if (socketFD < 0) 
		printf("ERROR opening socket\n");

	server = gethostbyname(argv[1]);
	if (server == NULL) 
	{
		printf("ERROR, no such host\n");
		exit(0);
	}
	
	

	bzero((char *) &serverAddress, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr,server->h_length);
	serverAddress.sin_port = htons(portNo);

	if (connect(socketFD,(struct sockaddr *) &serverAddress,sizeof(serverAddress)) < 0) 
		printf("ERROR connecting\n");

	printf("Client running on %s:%d\n",getSelfIPAddr(),getSelfPortNo(socketFD));

	if(!strcmp(inet_ntoa(serverAddress.sin_addr),"127.0.0.1"))
		printf("\n\nConnection established with %s:%d\n",getSelfIPAddr(),ntohs(serverAddress.sin_port));	
	else
		printf("\n\nConnection established with %s:%d\n",inet_ntoa(serverAddress.sin_addr),ntohs(serverAddress.sin_port));	
	
	printf("Me: ");
	bzero(buffer,256);
	fgets(buffer,255,stdin);

	n = write(socketFD,buffer,strlen(buffer));
	if (n < 0) 
		printf("ERROR writing to socket\n");

	bzero(buffer,256);
	n = read(socketFD,buffer,255);
	if (n < 0) 
		printf("ERROR reading from socket\n");

	printf("%s\n",buffer);

	close(socketFD);
	return 0;
}
