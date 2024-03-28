#include <stdio.h>
//scrivo un file con dimenzione standard
typedef struct
{
    unsigned int conto;
    char cognome[15];
    char nome[10];
    double bilamcio;
} Cliente;

int main()
{

    FILE *cfPtr;

    if ((cfPtr = fopen("C:/Unipa/Programmazione/File.txt/account.dat", "rb+")) == NULL)
    {
        puts("Il file .dat non puo essere aperto");
    }
    else
    {
        Cliente cliente = {0, "", "", 0.0};

        printf("%s", "Inserire numero del conto"
                     "(#1-#100, #0 per terminare): ");

        scanf("%d", &cliente.conto);

        while (cliente.conto != 0)
        {
            printf("%s", "\nInserire cognome, nome, bilancio: ");

            fscanf(stdin, "%14s%9s%lf", &cliente.cognome, &cliente.nome, &cliente.bilamcio);            

            fseek(cfPtr, (cliente.conto - 1) * (sizeof(Cliente)), SEEK_SET);

            fwrite(&cliente, sizeof(Cliente), 1, cfPtr);
            
            printf("%s", "\nInserire nuemro del conto: ");
            scanf("%d", &cliente.conto);            
        }

        fclose(cfPtr);
    }
}
