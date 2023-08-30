#include <stdio.h>

int main(void){

    int b[5];
    
    for (size_t i = 0; i < 4; i++)
    {
        b[i]=i;
    }
    
    int * bPtr;
    bPtr=b;
    int a=bPtr+3;

    printf("%d",a);
    
    
    
}