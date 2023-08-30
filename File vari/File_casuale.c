#include <stdio.h>
//creo un file con dimenzione standard
typedef struct 
{
    unsigned int conto;
    char cognome[15];
    char nome[10];
    double bilamcio;
}Cliente;

int main(){

    FILE *cfPtr;

    if ((cfPtr=fopen("C:/Unipa/Programmazione/File.txt/account.dat","wb")==NULL))
    {
        puts("Il file .dat non puo essere aperto");
    }else
    {
        Cliente cliente_tipo= {0,"","",0.0};

        for (size_t i = 0; i < 100; i++)
        {
            fwrite(&cliente_tipo,sizeof(Cliente),1,cfPtr);
        }

        fclose(cfPtr);
    }
}