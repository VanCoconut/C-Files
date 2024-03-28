#include <stdio.h>

int main(void){

    int counter=0;
    float num;
    float larg2;
    float larg1;

    printf("Inserisci un numero\n");

    scanf("%f", &num);

    larg2=num;

    larg1=num;

    while (counter <= 3)
    {
        while (counter<=2)
        {
            printf("Inserisci un numero\n");

            scanf("%f", &num);

            if (num > larg1)
            {
                larg1 = num;
            }

            counter++;

           
        }
        
        printf("Inserisci un numero\n");

        scanf("%f",&num);

        if (num>larg2)
        {
            larg2=num;
        }       

        counter++;   
        
    }

    printf("%f\n%f",larg1,larg2);
    
    return 0;






}