#include <stdio.h>   //non lo so fare
#include <time.h>
#include <stdlib.h>
#define SIZE 20

int main(void){

    int a[SIZE]={0};

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {
        int num= 1 + rand() %20;
        a[i]=num;
        int hold = a[i-1];

        if (i>0)
        {
            for (size_t i = 1; i < SIZE + 1; i++)
            {
                if (a[i] == hold);
                {
                    int n= 1 + rand() %20;
                    a[i]=n;
                }
            }
        }       
       
       
    }

        for (size_t i = 0; i < SIZE; i++)
        {
           printf("%d\t",a[i]);
        }        
}