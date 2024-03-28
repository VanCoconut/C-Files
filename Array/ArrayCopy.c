#include <stdio.h>
#include <string.h>

int main()
{
    //int a1[] = {1, 2, 3};
     int a1 = 7;
    int *a2=&a1;
    *a2=3;

     printf("%d\t", *a2);
    return 0;
}
