#include <stdio.h>
 
typedef struct 
{
    char *nome;
    char *cognome;
    int voto;
}Pagella;


int main(){

    FILE *cfPtr;

    if ((cfPtr = fopen("C:/Unipa/Programmazione/File.txt/test1.txt","w"))==NULL)
    {
        puts("Errore");
    }else
    {
        Pagella pagella; 
               

        //fprintf(cfPtr,"%s %s %d",n,c,v);
        pagella.nome="Piero";pagella.nome="Farsi";pagella.voto=6;
        fprintf(cfPtr, "%s %s %d",pagella.nome,pagella.cognome,pagella.voto);
        pagella.nome = "Piero";pagella.nome = "Farsi";pagella.voto = 6;
        fprintf(cfPtr, "%s %s %d", pagella.nome, pagella.cognome, pagella.voto);
    }
    fclose(cfPtr);
}