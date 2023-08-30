#include <stdio.h>
#include <stdlib.h>     / exit() /
#include <strings.h>    / bzero(), bcopy() /
#include <unistd.h>
#include <netinet/in.h>
#include <time.h>       / time_t e ctime() /
#include <sys/types.h>  / tipi di dati di sistema /
#include <sys/socket.h> / definizioni utili per le socket() /

//
// SERVER UDP
//

#define MAXLINE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
	int sockfd;
    int portno, clilen;
    int bytesread, counter;
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[MAXLINE], readLine[MAXLINE];


	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

	/*Inizializzazione dei parametri della socket*/
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
    	error("ERROR opening socket");
	}

	/*Creazione della socket*/
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
 		error("ERROR on binding");
	}

	clilen = sizeof(cli_addr);
	counter = -1;
	srand(time(NULL));
 	char ran=rand();
	
	while(counter<3) {

		counter++;
 		bzero(buffer, MAXLINE);		
 		bytesread = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr )&cli_addr, (socklen_t )&clilen);
 		if(strcmp(ran,buffer)==0){
			sendto(sockfd, "Hai vinto\n", 11, 0, (struct sockaddr *)&cli_addr, clilen);
			exit(0);
		}
		if(counter==2){
			sendto(sockfd, "Hai perso\n", 11, 0, (struct sockaddr *)&cli_addr, clilen);
			exit(0);
		}
		sendto(sockfd, "Riprova\n", 11, 0, (struct sockaddr *)&cli_addr, clilen);
		
 	}
	 
}