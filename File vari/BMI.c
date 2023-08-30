#include <stdio.h>

int main(void){

    float peso;
    float altezza;
    float BMI;

    printf("Inserire il proprio peso in kilogrammi\n");
    scanf("%f",&peso);

    printf("Inserire la propria altezza in metri\n");
    scanf("%f",&altezza);

    BMI=peso/(altezza*altezza);

    if (BMI<18.5)
    {
        printf("Sei sottopeso\n");        
    }else if (BMI<24.9 && BMI>18.5)
    {
        printf("Sei normale\n");
    }else if (BMI>24.5 && BMI<29.9)
    {
        printf("Sei in sovrappeso\n");
    }else if (BMI>30.0)
    {
        printf("Sei obeso\n");
    }else
    {
        printf("Dati inseriti non validi\n");
    }

    return 0;

}