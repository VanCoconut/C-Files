#include <stdio.h>
#include <stdlib.h>

int random(int);

int main(void){

    int n,x;
    
    srand(time(NULL));

    x=1+(rand() % 1000);

   printf("Ho un numero tra 1 e 1000.\n Indovina qual e' coglione!\n");
   

    for (size_t i = 0; i < 1000; i++)
    {   
        int counter;

        scanf("%d", &n);

        if (n==x)
        {
            printf("Hai indovinato\t");
            if (counter<11)
            {
                printf("Sei stato fortunato!\n");
            }else if (x>10 && x<21)
            {
                printf("Ahah!Sai il segreto!\n!");
            }else if (x>20)
            {
                printf("Puoi fare di meglio!\n");
            }
            
            
            
            
              break;      
        }else if (n<x)
        {
            printf("Troppo basso! Riprova, scemo!\n");
            n += 1 + rand() % (1000 - n);
        }else if (n>x)
        {
         printf("Troppo alto! Riprova di nuovo\n");
         n -= 1 + rand() % (1000 - n);
        }
        
        ++counter;
           
        }
}
    