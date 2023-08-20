#include <stdio.h>

int x = 0;

void piuUnoP(int *);
void piuUno(int);
void piuUnoPDueValori(int *, int *);
int piuUnoDueValori(int, int);
void piuUnoGlobal();
void printArray(int *, int size);

int main()
{
    int y = 5;

    int a = 1;
    int *b = &a;
    int c = 2;
    *b = 3;
    /*
        printf("Valore di a: %d\n",a);
        printf("Valore di b: %d\n",*b);
        printf("l'indirizzo di memoria di b: %d\n",&b);
        printf("l'indirizzo di memoria di a: %d\n",&a);
    */
    /*
        printf("y = %d", *y);
        piuUno(y);
        printf("y = %d", *y); */

    /*
        printf("x = %d\t y = %d", x,y);
        piuUnoPDueValori(&x,&y);
        printf("x = %d\t y= %d", x,y);
   */
}

void piuUnoP(int *n)
{
    *n = *n + 1;

    //*n++; il postincremento non funziona in questo caso, funziona per passare all'indice successivo di un array
    //++*n; il preincremento invece funziona anche in questo caso
}

void piuUno(int n)
{
    n++; // non ha effetti poiche alla funzione viene passata solo una copia
}

void piuUnoGlobal()
{
    x++;
}

void piuUnoPDueValori(int *a, int *b)
{
    *a = *a + 1;
    *b = *b + 1;
}
int piuUnoDueValori(int a, int b)
{

    return a++, b++; // non funziona poichè non ritorna il secondo valore
}

void printArray(int *array, int size)
{
    for (size_t i = 0; i < size; i++)
    {

        printf("%d\t", *array);
        array++;
    }
}