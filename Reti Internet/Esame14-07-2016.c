#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>       / funzioni time() e ctime() /
#include <unistd.h>
#include <sys/types.h>  / tipi di dati di sistema /
#include <sys/socket.h> / definizioni utili per le socket() /
#include <netinet/in.h>

//
// SERVER TCP
//

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd1,newsockfd2;
    int portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr1,cli_addr2;
    int n, counter;
    pid_t pid;

    counter = 0;

    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    while (1)
    {
        clilen1 = sizeof(cli_addr1);
        clilen2 = sizeof(cli_addr2);
        newsockfd1 = accept(sockfd, (struct sockaddr *)&cli_addr1, (socklen_t *)&clilen1);
        newsockfd2 = accept(sockfd, (struct sockaddr *)&cli_addr2, (socklen_t *)&clilen2);

        if (newsockfd1 < 0)
        {
            error("ERROR on accept");
        }
        if (newsockfd2 < 0)
        {
            error("ERROR on accept");
        }

        pid = fork();
        if (pid == 0)
        {
            close(sockfd);
            bzero(buffer, 256);
            buffer="Inviamelo tutto";

            n = write(newsockfd1, buffer, 255);
            if (n < 0)
            {
                error("ERROR writing to socket");
            }            
            n = read(newsockfd1, buffer, 255);
            if (n < 0)
            {
                error("ERROR reading from socket");
            }  
            
            n = write(newsockfd2, buffer, 255);           
            if (n < 0)
            {
                error("ERROR writing to socket");
            }
            n = write(newsockfd2, "Invia", 255);
            if (n < 0)
            {
                error("ERROR writing to socket");
            }
            n = read(newsockfd2, buffer, 255);
            if (n < 0)
            {
                error("ERROR reading from socket");
            }
            n = write(newsockfd1, buffer, 255);
            if (n < 0)
            {
                error("ERROR writing to socket");
            }
            close(newsockfd2);
            close(newsockfd1);
            return 0;
        }
        close(newsockfd2);
        close(newsockfd1);
    }
    return 0;
}