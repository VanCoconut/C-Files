#include <stdio.h>

int potenza(int a,int b);

int main(void){

    int esponente,base;
    printf("Digitare la base e l'esponente, separati da uno spazio\n");
    
    scanf("%d%d",&base,&esponente);   

    printf("%d elevato a %d fa %d\n",base,esponente,potenza(base,esponente));
    
}

int potenza(int a,int b){

    int potenza=1;
    

    for (int i = 0; i < b; i++)
    {
         potenza*=a;
    }

    return potenza;
}

