#include <stdio.h>

typedef struct
{
    unsigned int conto;
    char cognome[20];
    char nome[10];
    double bilancio;
}Cliente;

void txtFile(FILE *readPtr);

int main(){

    FILE *cfPtr;

    if ((cfPtr = fopen("C:/Unipa/Programmazione/File.txt/account.dat", "rb+")) == NULL)
    {
        puts("Il file .dat non si puo aprire");
    }else
    {
        txtFile(cfPtr);
    }
    
    

}

void txtFile(FILE *readPtr)
{

    FILE *writePtr;

    if ((writePtr = fopen("C:/Unipa/Programmazione/File.txt/account.txt", "w")) == NULL)
    {
        puts("Il file txt non puo essere aperto");
    }
    else
    {
        rewind(readPtr);
        fprintf(writePtr, "%-6s%-16s%-11s%10s\n");

        while (!feof(readPtr))
        {
            Cliente cliente = {0, "", "", 0.0};

            int result = fread(&cliente, sizeof(Cliente), 1, readPtr);

            if (result != 0 && cliente.conto != 0)
            {
                fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", cliente.conto, cliente.cognome, cliente.nome, cliente.bilancio);
            }
        }

        fclose(writePtr);
    }
}