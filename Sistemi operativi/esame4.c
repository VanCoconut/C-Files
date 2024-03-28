#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<wait.h>
#include <string.h>

void sigign();

void main(){
    pid_t pid1, pid2, pid3;
    int child_status_1, child_status_2, child_status_3, fd_1[2], fd_2[2], fd_3[2];

    pipe(fd_1);
    pipe(fd_2);
    pipe(fd_3);
    pid1=fork();

    if(pid1==0){
        
        pid3=fork();
        if(pid3==0){
            //F3
            while(1) {
            signal(2,sigign);
            signal(15,sigign);
            signal(19,sigign);
            }
        }
        else{
            //F1
            char nome[10];
            int numero;
            close(fd_1[1]);
            read(fd_1[0], nome, sizeof(nome));
            printf("F1: Ho ricevuto: %s, invio ad F2\n", nome);
            close(fd_2[0]);
            write(fd_2[1], nome, sizeof(nome));

            close(fd_3[1]);
            read(fd_3[0], &numero, sizeof(numero));
            printf("F1: Ho ricevuto il numero: %d, invio il segnale a F3\n", numero);
            kill(pid3, numero);
        }
    }

    else{
        pid2=fork();
        if(pid2==0){
            //F2
            char nome[10];
            int numero=0;
            close(fd_2[1]);
            read(fd_2[0], nome, sizeof(nome));
            printf("F2: Ho ricevuto: %s\n", nome);

            if(strcmp(nome, "SIGCONT")==0){
                numero=19;
                printf("F2: Invio a F1 il numero: %d\n", numero);
            }
            if(strcmp(nome, "SIGINT")==0){
                numero=2;
                printf("F2: Invio a F1 il numero: %d\n", numero);
            }

            if(strcmp(nome, "SIGTERM")==0){
                numero=15;
                printf("F2: Invio a F1 il numero: %d\n", numero);
            }

            /*else{
                puts("segnale non supportato");
                return;
            }*/
            printf("F2: Invio a F1 il numero: %d\n", numero);
            close(fd_3[0]);
            write(fd_3[1], &numero, sizeof(numero));

        }
        else{
            //P
            char nome[10];
            printf("P: Inserire il nome di un signal: ");
            scanf("%s", nome);
            puts("");

            close(fd_1[0]);
            write(fd_1[1], nome, sizeof(nome));
        }
    }
    wait(&child_status_1);
    wait(&child_status_2);
    wait(&child_status_3);
}

void sigign() {
    printf("Segnale ricevuto, ignoro!\n");
    exit(0); 
}