#include <stdio.h>

typedef struct
{
    unsigned int accountN;
    char lastName[15];
    char firstName[10];
    double balance;
} ClientData;

int main()
{

    FILE *pF;

    if ((pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\accounts.dat", "wb")) == NULL)
    {
        puts("No such file");
    }
    else
    {
        ClientData client = {0, "", "", 0.0};

        puts("Enteran account number (1-100) or 0 to close");
        scanf("%d", &client.accountN);

        while (client.accountN != 0)
        {
            puts("Enter last name, first name, balance");

            //if fscanf can't properly read the input it returns the Eof and so it will skip the iteration
            //it should be improved with error input controls
           fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance);

           /* prova inutile per evitare overflow
            fscanf(stdin, "%14s", client.lastName );
            scanf("%s");
            printf("%s\n",client.lastName);
            fscanf(stdin, "%9s",  client.firstName);
             scanf("%s");
            printf("%s\n",client.firstName);
            fscanf(stdin, "%lf",  &client.balance);
            printf("%f\n",client.balance);
            //scanf("%14s%9s%lf", client.lastName, client.firstName, &client.balance);
           */



            fseek(pF, (client.accountN - 1) * sizeof(ClientData), SEEK_SET);

            fwrite(&client, sizeof(ClientData), 1, pF);

            puts("Enteran account number (1-100) or 0 to close");
            scanf("%d", &client.accountN);
        }

        fclose(pF);
    }
    return 0;
}