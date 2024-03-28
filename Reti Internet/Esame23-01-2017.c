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

int main(int argc, char *argv[]){
    int sockfd, newsockfd;
    int portno, clilen;
    char buffer[256],name[20],str[30]="Hello ";
    struct sockaddr_in serv_addr, cli_addr;
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

    if (bind(sockfd, (struct sockaddr *)&serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    while(1){
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,(socklen_t *)&clilen;

        if (newsockfd < 0){
            error("ERROR on accept");
        }

        pid = fork();

        if (pid == 0){

            close(sockfd);
            while (1)
            {
                bzero(buffer, 256);
                n = read(newsockfd, buffer, 255);
                if (n < 0){          
                    error("ERROR reading from socket");
                }
                const char s[2] = " ";  
                token = strtok(buffer, s);
                if (strcmp("Hello!", token) != 0){
                    n = write(newsockfd, "Wrong message %s", 30);
                    continue;
                }
                token = strtok(NULL, s);

                if (strcmp("My", token) != 0){
                    n = write(newsockfd, "Wrong message %s", 30);
                    continue;
                }

                token = strtok(NULL, s);

                if (strcmp("name", token) != 0){
                    n = write(newsockfd, "Wrong message %s", 30);
                    continue;
                }
                token = strtok(NULL, s);

                if (strcmp("is", token) != 0){
                    n = write(newsockfd, "Wrong message %s", 30);
                    continue;
                }
                token = strtok(NULL, s);
                strcpy(char name[20], token);
                return 0;
            }
            strcat(str,name);

            n = write(newsockfd,str, 30);
            if (n < 0){
                error("ERROR writing to socket");
            }
        }          
    }
    return 0;
}

