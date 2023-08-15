#include <stdio.h>

int main(){

    int a = 1;
    int *b = &a;
    int c = 2;
    *b=3;
    printf("Valore di a: %d\n",a);
    printf("Valore di b: %d\n",*b);



    return 0;
}