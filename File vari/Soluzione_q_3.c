#include <stdio.h>

typedef struct 
{
    char nome[20];
    char cognome[20];
    int eta;
}Persona;

Persona get_giovane(Persona persone[],int num);

int main(){

    FILE *cfPtr;

    if ((cfPtr = fopen("C:/Unipa/Programmazione/File.txt/persone.txt","r"))==NULL)
    {
        puts("Errore");
    }else
    {
        int num;
        fscanf(cfPtr,"%d",&num);
        printf("Il registro possiede %d record\n",num);
        Persona persona_corrente;
        Persona persone[num];
        for (size_t i = 0; i < num; i++)
        {
            fscanf(cfPtr,"%19s%19s%d",persona_corrente.nome,persona_corrente.cognome,&persona_corrente.eta);
            persone[i]=persona_corrente;
            printf("%s %s %d\n",persona_corrente.nome,persona_corrente.cognome,persona_corrente.eta);
        }
        fclose(cfPtr);
        Persona giovane=get_giovane(persone,num);
        printf("La eprsona piu giovane e : %s %s con %d anni",giovane.nome,giovane.cognome,giovane.eta);        
    } 
}

Persona get_giovane(Persona persone[], int num){

    Persona giovane=persone[0];

    for (size_t i = 1; i < num; i++)
    {
        if (persone[i].eta<giovane.eta)
        {
            giovane=persone[i];
        }           
    }
    return giovane;
}