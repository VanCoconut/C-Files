#include <stdio.h>
#include <stdlib.h>



int main(void)
{

    int n, x;

    srand(time(NULL));
    x = 1 + (rand() % 1000);

    n = rand() % 52;
    srand(n);
    n = 1 + rand() % 1000;

    printf("Ho un numero tra 1 e 1000.\t Indovina qual e' coglione!\n");

    for (size_t i = 0; i < 1001; i++)
    {
        unsigned int counter,y,z;
        z=n;

        if ( z == x)
        {
            printf("Hai indovinato\n. Il  numero era: %u\n",z);
            printf("Numero di tentativi : %u", counter);
            break;
        }else if (z < x)
        {
            printf("Numero scelto: %u\t Troppo basso! Riprova, scemo!. Hai fatto %u tentativi \n",z,counter);

           // y = n;
            z += 1 + rand() % (1000-z);
           
          
            
        }
        else if (z > x)
        {
            printf("Numero scelto: %u\t Troppo alto! Riprova di nuovo. Hai fatto %u tentativi\n",z,counter);
            //y=n;
            z -= 1+ rand() % (1000-z);

           
            


        }/*if (i=999)
        {
            printf("Numero di tentativi : %d", counter);
        }
        */
        ++counter;
    }
}
