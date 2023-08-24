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

    if ((pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\accounts.dat", "rb+")) == NULL)
    {
        puts("No such file");
    }
    else
    {

        printf("%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

        while (!feof(pF))
        {
            ClientData client = {0, "", "", 0.0};

            int result = fread(&client, sizeof(ClientData), 1, pF);

            if (result != 0)
            {
                printf("%-6d%-16s%-11s%10.2f\n", client.accountN, client.lastName,
                       client.firstName, client.balance);
            }
        }
        fclose(pF);
    }
    return 0;
}