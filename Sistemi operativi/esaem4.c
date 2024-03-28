#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

int main()
{
    pid_t pid1, pid2, pid3;
    int child_status_1, child_status_2, child_status_3, fd_1[2], fd_2[2], fd_3[2];

    pipe(fd_1);
    pipe(fd_2);
    pipe(fd_3);

    pid1 = fork();
    if (pid1 == 0){

        if (pid3==0){
            //F3    
            int v;
            close(fd_3[1]);
            read(fd_3[0], &v, sizeof(v));
            signal();
        }
        else{

        // F1
        char b[10];
        close(fd_2[1]);
        read(fd_2[0],&b,sizeof(b));
        printf("F1: Ho ricevuto il numero del segnale!\n");
        
        close(fd_1[1]);
        write(fd_1[0], &b, sizeof(b));        
        printf("F1: Ho inviato il numero del segnale!\n");
        }
    }

    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            // F2
            char c[10];
            int i=0;
            close(fd_1[1]);
            read(fd_1[0], &c, sizeof(c));
            printf("F2: ho ricevuto il segnale %s\n", c);

            if (strcmp(c,"SIGHUP"))
            {
                 i=1;
                close(fd_3[1]);
                write(fd_3[0], &i, sizeof(i));
            }
            if (strcmp(c, "SIGTRAP"))
            {
                 i = 2;
                close(fd_3[1]);
                write(fd_3[0], &i, sizeof(i));
            }
            if (strcmp(c, "SIGKILL"))
            {
                i = 3;
                close(fd_3[1]);
                write(fd_3[0], &i, sizeof(i));
            }

            printf("F2: ho inviato il  processo %d\n", c, b);
        }
        else
        {
            // P
            char a[10];            
            printf("P: Inserire il nome di un segnale: ");
            scanf("%s",a);
            close(fd_2[0]);
            write(fd_2[1], &a, sizeof(a));
            printf("P: Ho inviato il segnale: %s\n", a);
        }
    }
    wait(&child_status_1);
    wait(&child_status_2);
    wait(&child_status_3);

    return 0;
}
