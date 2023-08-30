#include <stdio.h>

int multiplo(int a,int b);

int main(void){

    int num1,num2,resto;

    printf("Inserire i due numeri per sapere se sono multipli\n");

    scanf("%d%d",&num1,&num2);

    int cod = multiplo(num1, num2);

    if (cod==1)
    {
        printf("%d e' un multiplo di %d, la loro divisione fa %d\n",num2,num1,num2/num1);
    }else
    {
        printf("%d non e' un multiplo intero di %d, la loro divisione fa %d\n", num2, num1);
    }    
    
    printf("Codice di ritorno %d\n",cod);

}

int multiplo(int a,int b){

    int r=b%a;    

    if (r == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}