#include <stdio.h>

typedef struct 
{
    unsigned int accountN;
    char lastName[15];
    char firstName[10];
    double balance;
} ClientData;


int main(){

    FILE *pF;

    if ((pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\accounts.dat","wb"))== NULL)
    {
        puts("No such file");
    } else
    {
        ClientData blankClient={0,"","",0.0};

        for (size_t i = 0; i < 100; i++) // if doesn't work try i=1 and i<101
        {
            fwrite(&blankClient,sizeof(ClientData),1,pF);
        }
        fclose(pF);
    }
    return 0;
}