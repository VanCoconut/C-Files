#include <stdio.h>

int main(void){

    int num1,num2,num3,numserie;

    printf("Quanti numeriri della serie di Fibonacci vuoi visualizzare?\n");

    scanf("%d",&numserie);

    printf("I primi %d numeri della serie di Fibonacci sono:\n", numserie);

    num1,num2=1,1;
   
    printf("%d\n%d\n",num1,num2);

    for (int i = 2; i < numserie; i++)
    {
        num3=num1+num2;
        num1=num2;
        num2=num3;
        printf("%d\n",num3);
    }
    

   

}