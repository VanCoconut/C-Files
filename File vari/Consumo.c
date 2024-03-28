#include <stdio.h>


int main(void){

    float kilometri;
    float litri;
    float rapporto;

    printf("Inserire i kilometri percorsi (-1 per terminare)\n");

    scanf("%f", &kilometri);  

    if (kilometri==-1)
    {
        printf("Arresto del programma");
    }
   
    while (kilometri!=-1)
    {
        printf("Inserire i litri utilizzati \n");

        scanf("%f", &litri);        

        rapporto=kilometri/litri;

        printf("Il consumo registrato e' di %.3f kilometri su litro\n",rapporto);

        printf("Inserire i kilometri percorsi (-1 per terminare)\n");

        scanf("%f", &kilometri);

        if (kilometri == -1)
        {
            printf("Arresto del programma");
        }
    }
    

    
}