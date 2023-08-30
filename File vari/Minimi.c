#include <stdio.h>

int main(void){

    int num,min=999999,j;

    printf("Quanti valori vuoi inserire?\n");

    scanf("%d",&j);

    for (int i=0 ; i < j; i++)
    {
        printf("Inserisci un valore\n");
        scanf("%d",&num);        
        if (num<min)
        {
            min=num;
        }
    
    }

    printf("Il minimo e':%d",min);
    

}