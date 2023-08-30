#include <stdio.h>

int quadrato(int x);

int main(void){

    for (int i = 1 ; i <=10; i++)
    {
        printf("%d",quadrato(i));
    }

    
}

int quadrato(int x){

    return x*x;
}