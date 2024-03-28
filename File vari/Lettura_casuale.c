#include <stdio.h>
//leggo il file .dat
typedef struct 
{
    unsigned int conto;
    char cognome[15];
    char nome[10];
    double bilancio;
}Cliente;

int main(){

    FILE *cfPtr;

    if ((cfPtr = fopen("C:/Unipa/Programmazione/File.txt/account.dat","rb"))==NULL)
    {
        puts("Il file non puo essere aperto");
    }else
    {
        printf("%-6s%-16s%-11s%10s\n","Conto","Cognome","Nome","Bilancio");

        while (!feof(cfPtr))
        {
            Cliente cliente={0,"","",0.0};
            
            int result=fread(&cliente,sizeof(Cliente),1,cfPtr);

            if (result!=0 && cliente.conto!=0)
            {
                printf("-6d%-16s%-11s%-10.2f\n",cliente.conto,cliente.cognome,cliente.nome,cliente.bilancio);                
            }
            
        }
        
    }
    
    
}
