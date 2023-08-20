#include <stdio.h>

void piuUnoP(int *);
void piuUno(int );
int x=7;
int main()
{
    int *y;
    *y=5;

 
    int a = 1;
    int *b = &a;
    int c = 2;
    *b = 3;
    /*  printf("Valore di a: %d\n",a);
     printf("Valore di b: %d\n",*b);
     printf("l'indirizzo di memoria di b: %d\n",&b);
     printf("l'indirizzo di memoria di a: %d\n",&a); */
/* 
    printf("y = %d", *y);
    piuUno(y);
    printf("y = %d", *y); */

    printf("x = %d", x);
    piuUnoP(&x);
    printf("x = %d", x);

    return 0;
}

void piuUnoP(int *n)
{
    *n = *n + 1;
}

void piuUno(int n)
{
    n++;
}