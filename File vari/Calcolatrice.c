#include <stdio.h>
#include <math.h>
int main(void)
{

    float num1;
    float num2;
    char operazione;
   
    printf("Scrivere l'operazione da svolgere\n");

    scanf("%f%c%f",&num1,&operazione,&num2);     

    float somma = num1 + num2;
    float sottrazione = num1 - num2;
    float prodotto = num1 * num2;
    float divisione = num1 / num2;
    float potenza = pow(num1,num2);
    float radice2 =  num1*0 + sqrt(num2);
    //float ln = num1*0 + logf(num2);

    switch (operazione)
    {
    case '+':
        printf("La somma e': %f", somma);
        break;

    case '-':
        printf("la sottrazione e': %f", sottrazione);
        break;

    case '*':
        printf("La prodotto e': %f", prodotto);
        break;

    case '/':
        if (num2 == 0)
        {
            printf("ERRORE IMPOSSIBILE DIVIDERE PER 0 ");
            break;
        }
        else
        {
            printf("La divisione e': %f", divisione);
            break;
        }
        break;

    case '^':
        printf("La potenza e': %f",potenza);
        break;

    case 'r':
        printf("La radice quadrata e': %f",radice2);
        break;

    //case 'ln':
       // printf("Il logaritmo naturale e': %f",ln);
        //break;

    default:
        printf("Operatore non valido");
        break;
    }

    
}