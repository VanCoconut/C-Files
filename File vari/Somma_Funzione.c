#include <stdio.h>

int somma(int,int);

int main(void){

    int num1,num2;

    printf("Inserire i numeri da sommare\n");
    scanf("%d%d",&num1,&num2);

    printf("La somma e': %d",somma(num1,num2));
}

int somma(int a,int b){

        return a+b; 
        
}