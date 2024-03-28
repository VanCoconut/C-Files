#include <stdio.h>

int descending(int, int);
int ascending(int, int);
void bubleSort(int[], int, int (*)(int, int));

int main()
{
    int a[] = {13, 11, 2, 1, 12};
    int size = sizeof(a) / sizeof(a[0]);
    bubleSort(a, size, ascending);
    for (size_t i = 0; i < size; i++)
    {
        printf("%5d", a[i]);
    }

    return 0;
}

// usaimo un puntatore ad una funzione come argomento per poterla intercambiare facilmente (polimorfismo)
void bubleSort(int a[], int size, int (*compare)(int x, int y))
{
    void swap(int, int);
    void swapP(int *, int *);

    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            // int c=(*compare)(a[j], a[j + 1]);
            // printf("\n%d\n",c);
            if ((*compare)(a[j], a[j + 1]))
            {
                swapP(&a[j], &a[j + 1]);
                // printf("a[j] = %d, a[j+1] = %d\n",a[j],a[j+1]);
            }
        }
    }
}

// non modifica valori quindi non ha bisogno di puntatori
int ascending(int a, int b)
{
    // c doesn't have boolean so 0 is "false" 1 "true"
    return b < a;
}
int descending(int a, int b)
{
    // c doesn't have boolean so 0 is "false" 1 "true"
    return b > a;
}

// se non si usano i puntatori la funzione cambia i valori solo al suo interno e non nel ciclo for di buble
void swapP(int *a, int *b)
{
    int hold = *a;
    *a = *b;
    *b = hold;
    // printf("a = %d, b = %d\n",*a,*b);
}

// se non si usano i puntatori la funzione cambia i valori solo al suo interno e non nel ciclo for di buble
void swap(int a, int b)
{
    int hold = a;
    a = b;
    b = hold;
    printf("a = %d, b = %d\n", a, b);
}
