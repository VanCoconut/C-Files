#include <stdio.h>
#include <string.h>

int main()
{
    int a1[] = {1, 2, 3};
    int *a2 = a1;
    int a3[3];
    a2[0] = 0;

    memcpy(a3, a1, sizeof(a1));

    a3[1]=5;

    for (size_t i = 0; i < 3; i++)
    {
        printf("%d\t", a1[i]);
    }

    return 0;
}