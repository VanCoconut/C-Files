#include <stdio.h>

void printArray(int *array, int size)
{
    for (size_t i = 0; i < size; i++)
    {

        printf("%d\t", *array);
        array++;
    }
}

int main()
{

    int b[] = {1, 2, 3, 4, 5};
    int *pB = b;
    int n = *(pB + 1); // to initialize a int using the offset
    int *x = pB + 1;   // to initialize a pointer to int using the offset same as pB++
    int y = pB[1];     // a pointer is the same of an array
    printf("b[1] = %d\n", y);

    // due modi per sottrarre due puntatori
    // farlo ha senso solo quando puntano allo stesso array ma con indici diversi
    // il risultato è la differenza di subscripts (pedici)
    int array[] = {1, 2, 3, 4, 5};
    int *v1 = &array[0]; // equals to =array;
    int *v2 = &array[4];
    int v3 = v2 - v1;
    int *t = pB + 2;
    int *u = pB;
    int v = (pB + 2) - (pB);
    printf("la distanza tra i due puntatori è : %d", v3);

    return 0;

    return 0;
}