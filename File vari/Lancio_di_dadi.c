#include <stdio.h>
#include <stdlib.h>

int main(void){

    int sum;

    for (unsigned i = 0; i < 50; i++)
    {
        int face=1+rand()%6;
        printf("Face is :\t%d\n",face);
        sum+=face;
    }

     
    printf("The averange number is :\t%d\n", sum/50);
}