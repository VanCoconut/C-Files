#include <stdio.h>

typedef struct 
{
    unsigned int nome[10];
    char cognome[15];
    double eta;
}Persona;


int main(){

    FILE *cfPtr;

    

    if ((cfPtr=fopen("C:/Unipa/Programmazione/File.txt/persone.txt", "r"))==NULL)
    {
        puts("Il file non puo essere aperto");
    }else
    {          
        //printf("%-10s%-12s%s\n","Conto","Nome","Bilancio");
        Persona persona;
        int num;
        fscanf(cfPtr,"%d",&num);
                    
        while (!feof(cfPtr))
        {
            fscanf(cfPtr, "%9s%14s%d\n", persona.nome,persona.cognome,&persona.eta);
            printf("%-10s%-13s%7d\n", persona.nome, persona.cognome, persona.eta);                           
        }
            
    }    
}