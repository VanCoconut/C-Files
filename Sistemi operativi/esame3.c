#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h> 

void main(){
    pid_t pid1, pid2;
    int child_status_1, child_status_2, fd_1[2], fd_2[2], fd_3[2];

    pid1=fork();

    if(pid1==0){
        //F1
        int a;
        close(fd_1[1]);
        read(fd_1[0], &a, sizeof(a));
        printf("F1: Ho ricevuto %d. Invio a F2.\n", a);
        close(fd_2[0]);
        write(fd_2[1], &a, sizeof(a));
    }
    else{
        pid2=fork();

        if(pid2==0){
            //F2
            int b;
            close(fd_2[1]);
            read(fd_2[0], &b, sizeof(b));
            printf("F2: Ho ricevuto %d. Invio a P.\n", b);
            close(fd_3[0]);
            write(fd_3[1], &b, sizeof(b));
        }

        else{
            //P
            int r= rand();
            printf("P: Invio il numero: %d\n", r);
            close(fd_1[0]);
            write(fd_1[1], &r, sizeof(r));
            int a;
            close(fd_3[1]);
            read(fd_3[0], &a, sizeof(a));
            printf("P: Ho ricevuto %d.\n", a);
            if(a==r){
                puts("P: Il numero è uguale!!!!");

            }
            else{
                puts("P: a rinoglionito ao");
            }
        }
        
    }
    wait(&child_status_1);
    wait(&child_status_2);
    
}