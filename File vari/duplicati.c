#include <stdio.h>
#define SIZE 20

int main(void){ 

    int a[SIZE];

    for (size_t i = 0; i < SIZE; i++)
    {
        a[i] = 10+i;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        if (a[i]==a[i+1])
        {
            continue;
        }
        
        printf("%d\t", a[i]);
    }
}