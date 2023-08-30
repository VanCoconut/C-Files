#include <stdio.h>

int main(void){

    int num1,num2,num3;

        
        printf("Inserire 3 numeri, separati da uno spazio, da 1 a 30\n");
        scanf("%d%d%d", &num1,&num2,&num3);
        printf("\n");
        for (int i = 0; i < num1; i++)
        {
            printf("|");
        }
        printf("\n");
        for (int i = 0; i < num2; i++)
        {
            printf("|");
        }
        printf("\n");
        for (int i = 0; i < num3; i++)
        {
            printf("|");
        }
        printf("\n\n");
}
    