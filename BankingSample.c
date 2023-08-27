#include <stdio.h>
#include <ctype.h>

typedef struct
{
    unsigned int accountN;
    char lastName[15];
    char firstName[10];
    double balance;
} ClientData;

unsigned int clientChoice(void);
void setTxtFile(FILE *pF);
void updateAccount(FILE *pF);
void newAccount(FILE *pF);
void deleteAccount(FILE *pF);

int main()
{

    FILE *pF;

    if ((pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\accounts.dat", "rb+")) == NULL)
    {
        puts("Error opening the file");
    }
    else
    {
        unsigned int choice = 0;

        while ((choice = clientChoice()) != 5)
        {
            switch (choice)
            {
            case 1:
                setTxtFile(pF);
                break;
            case 2:
                updateAccount(pF);
                break;
            case 3:
                newAccount(pF);
                break;
            case 4:
                deleteAccount(pF);
                break;
            default:
                puts("Choice not supported");
                break;
            }
        }
        fclose(pF);
    }

    return 0;
}

unsigned int clientChoice(void)
{

    puts("Select one action:\n"
         "1 - set the file \n"
         "2 - update an existing account\n"
         "3 - add a new account\n"
         "4 - delete an account\n"
         "5 - end program\n");
    unsigned int choice = 0;
    scanf("%d", &choice);
    if (choice == 1)
    {
        puts("YOU WILL UPDATE ANY INFORMATION STORED BEFORE\nContinue? (Y,N)");
        char confirm;
        scanf("%c");
        scanf("%c", &confirm);
        if ((toupper(confirm)) == 'Y')
        {
            return choice;
        }
        else
        {
            puts("Choice cancelled");
            return 0;
        }
    }
    return choice;
}
void setTxtFile(FILE *readP)
{

    // this function need the file "RandomFileSet.c" to be runned first to set the .dat files uses at line 14

    FILE *writeP;
    if ((writeP = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\accounts.txt", "wb+")) == NULL)
    {
        puts("Error opening the file");
    }
    else
    {
        rewind(readP); // rewind is not safe, use fseek pointing to the first byte instead

        if(fprintf(writeP, "%-7s%-16s%-11s%10s\n", "AccNum", "Last Name", "First Name", "Balance")!=4){
            puts("Error line 102");
        }

        while (!feof(readP))
        {
            ClientData client = {0, "", "", 0.0};

            int result = fread(&client, sizeof(ClientData), 1, readP);

            if (result == 1 && client.accountN != 0)
            {
                int r = fprintf(writeP, "%-6d%-16s%-11s%10.2f\n", client.accountN, client.lastName, client.firstName, client.balance);

                if (r != 4)
                {
                    puts("Error writing on text file");
                }
            }
        }
        fclose(writeP);
    }
}
void updateAccount(FILE *pF)
{

    puts("Enter the account number (1-100)");

    unsigned int account = 0;
    scanf("%d", &account);

    if (fseek(pF, (account - 1) * sizeof(ClientData), SEEK_SET) != 0)
    {
        puts("Error finding the position");
    }

    ClientData client = {0, "", "", 0.0};

    int r = fread(&client, sizeof(ClientData), 1, pF);

    if (client.accountN == 0)
    {
        printf("Account n. #%d has no information\n", account);
    }
    if (r == 1)
    {

        printf("%-6d%-16s%-11s%10.2f\n", client.accountN, client.lastName,
               client.firstName, client.balance);

        puts("Enter the charge (+) or the payment (-)");
        double transaction = 0;
        scanf("%lf", &transaction);
        client.balance += transaction;
        printf("%-6d%-16s%-11s%10.2f\n", client.accountN, client.lastName,
               client.firstName, client.balance);

        
            if (fseek(pF, (account - 1) * sizeof(ClientData), SEEK_SET) != 0)
            {
                puts("Error finding the position");
            }

        if (fwrite(&client, sizeof(ClientData), 1, pF) != 1)
        {
            puts("Error writing the data");
        }
    }
}
void newAccount(FILE *pF)
{
    puts("Enter the account number (1-100)");

    unsigned int account = 0;
    scanf("%d", &account);

    if (fseek(pF, (account - 1) * sizeof(ClientData), SEEK_SET) != 0)
    {
        puts("Error finding the position");
    }
    ClientData client = {0, "", "", 0.0};

    fread(&client, sizeof(ClientData), 1, pF);
    if (client.accountN != 0)
    {
        printf("Account n.#%d already contains information\n");
    }
    else
    {

        puts("Enter last name, first name, balance");
        int r = fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance);

        while (r != 3)
        {
            puts("Error, please enter last name, first name, balance");
            r = fscanf(stdin, "%14s%9s%lf", client.lastName, client.firstName, &client.balance);
        }
        
        client.accountN=account;

        if (fseek(pF, (account - 1) * sizeof(ClientData), SEEK_SET) != 0)
        {
            puts("Error finding the position");
        }

        if (fwrite(&client, sizeof(ClientData), 1, pF) != 1)
        {
            puts("Error writing the data");
        }
    }
}
void deleteAccount(FILE *pF)
{
    puts("Enter the account number (1-100)");

    unsigned int account = 0;
    scanf("%d", &account);

    if (fseek(pF, (account - 1) * sizeof(ClientData), SEEK_SET) != 0)
    {
        puts("Error finding the position");
    }
    ClientData client = {0, "", "", 0.0};

    int r = fread(&client, sizeof(ClientData), 1, pF);

    if (client.accountN == 0)
    {
        printf("Account n.#%d does not contain any information\n");
    }
    if (r == 1)
    {
        if (fseek(pF, (account - 1) * sizeof(ClientData), SEEK_SET) != 0)
        {
            puts("Error finding the position");
        }
        ClientData blankClient = {0, "", "", 0.0};

        if (fwrite(&blankClient, sizeof(ClientData), 1, pF) != 1)
        {
            puts("Error writing the data");
        }
    }
}