#include <stdio.h>

int main(){
    
    FILE *cfPtr;  //puntatore al file lista_sequ.txt

    //apro/creo il file lista_sequ.txt
    if ((cfPtr = fopen("C:/Unipa/Programmazione/File.txt/test1.txt", "w")) == NULL)
    {
        puts("Il file non puo essere aperto");
    }
    else
    {
        puts("Inserire nuemro account, cognome, nome e bilancio");
        puts("Inserire sequenza EOF (ctrl+z) per salvare e termianre");
        printf("%s","?");     
    
    unsigned int account;    
    char cognome[15];
    char nome[10];
    double bilancio;
     

    scanf("%d%14s%9s%lf",&account,cognome,nome,&bilancio);

    while (!feof(stdin))
    {   //scrivo sul terminale cio che voglio scrivere nel file 
        fprintf(cfPtr,"%d  %s  %s  %.2f\n",account,cognome,nome,bilancio);
        printf("%s","?");
        scanf("%d%14s%9s%lf", &account, cognome,nome, &bilancio);
    }
    fclose(cfPtr);
    
    }
}