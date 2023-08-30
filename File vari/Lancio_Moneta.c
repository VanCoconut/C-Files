#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int flip();

int main(void){

    int testa,croce,seed;    

    printf("Inserire seed\n");

    scanf("%d",&seed);
    
    srand(seed);

    for (int i = 1; i < 100; i++)
    {
        int face=flip();
        if (face==1)
        {
            ++croce;
        }else
        {
            ++testa;
        }
       
    }

    printf("E' uscito croce %d volte\n", croce);
    printf("E' uscito testa %d volte\n", testa);
}

int flip(){
    
    return 1+rand()%2;
    
}