#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h> 

int main(){ 
    pid_t pid1, pid2;
    int child_status_1, child_status_2, fd_1[2], fd_2[2];

    pipe(fd_1);
    pipe(fd_2);

    pid1=fork();
    if (pid1==0){
        //F1
        int n;
        printf("F1: Inserire il numero del segnale tra 0 e 31: ");
        scanf("%d", &n);
        if(n<0 && n>31){
            exit(1);
        }
        close(fd_1[0]);
        write(fd_1[1], &n, sizeof(n));
        printf("F1: Ho inviato il numero del segnale!\n");
    }

    else{
        pid2=fork();
        if (pid2==0){
            //F2
            int b, c;
            printf("F2: Inserire un PID disponibile: ");
            scanf("%d", &b);
            close(fd_2[1]);
            read(fd_2[0], &c, sizeof(c));

            kill(b, c);
            printf("F2: ho inviato il segnale %d al PID %d\n", c, b);

        }
        else{
            //P
            int a;
            close(fd_1[1]);
            read(fd_1[0], &a, sizeof(a));
            printf("P: Ho ricevuto il numero: %d\n", a);
            close(fd_2[0]);
            write(fd_2[1], &a, sizeof(a));
            printf("P: Ho inviato il numero: %d\n", a);
        }
    }
    wait(&child_status_1);
    wait(&child_status_2);

    return 0;
}
