#include <stdio.h>

int main(void){

    int account_number;
    float bilancio_I;
    float addebbiti;
    float accrediti;
    float credito;
    float bilancio_F;

    printf("Inserire il numero dell'account, oppure inserire \"-1\" per terminare\n");

    scanf("%d",&account_number);

    if (account_number== -1)
    {
        printf("Arresto del programma");
    }

    while (account_number!=-1)
    {


        printf("Inserire bilancio iniziale \n");

        scanf("%f",&bilancio_I);

        printf("Inserire totale accrediti\n");

        scanf("%f",&accrediti);

        printf("Inserire totale addebbiti\n");

        scanf("%f",&addebbiti);

        printf("Inserire credito massimo\n");

        scanf("%f",&credito);

        bilancio_F=bilancio_I+accrediti-addebbiti;        

        if (bilancio_F>=credito)
        {
            printf(" Account number: %d\n Bilancio finale: %f\n Massimo credito erogabile: %f\n CREDITO LIMITE SUPERATO\n\n",account_number,bilancio_F,credito);
        }else
        {
            printf("Saldo registrato\n\n");
        }        

        printf("Inserire il numero dell'account, oppure inserire \"-1\" per terminare\n");

        scanf("%d", &account_number);

        if (account_number == -1)
        {
            printf("Arresto del programma");
        }
    }

    return 0;
    
}