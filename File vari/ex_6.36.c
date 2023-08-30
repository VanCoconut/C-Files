#include <stdio.h>
#define SIZE 6

void printArray(char a[], int size);

int main()
{

    char a[SIZE] = "ciao";

    printArray(a, SIZE);
}

void printArray(char a[], int size)
{

    if (size == 0)
    {
        return;
    }
    else
    {
        // printf("Il valore di size e': %d\t", size);
        printf("%c", a[size - 1]);
        printArray(a, size - 1);
    }
}