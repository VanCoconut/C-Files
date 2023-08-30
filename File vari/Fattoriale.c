#include <stdio.h>

int main(void){

    int num;
    int fattoriale=1;
    printf("Inserire un numero\n");
    scanf("%d",&num);
    fattoriale=num;
    
    for (int i=num-1; i >1; i--)
    {
        fattoriale*=(i);
    } 
    
    printf("%d! = %d",num,fattoriale);
    return 0;
}