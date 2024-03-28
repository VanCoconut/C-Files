#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 13

int main(void){

    int frequenza[SIZE]={0};
    
    srand(time(NULL));
    
    for (size_t i = 1; i < 36000; i++)
    {
        size_t face1= 1 + rand() %6;
        size_t face2= 1 + rand() %6;

        size_t  face = face1 + face2;

        ++frequenza[face];
    }
    
    printf("%s%17s\n","Somma delle 2 facce","Frequenza");

    for (size_t face = 2; face < SIZE; face++)
    {

       printf("%10d%26d\n",face,frequenza[face]);
    
    }
    puts("");
    //per verificare che le probabilità siano reali 
    float prob= (float) frequenza[7];
    printf("La probabilita' di 7 deve circa 0.16; quella calcolata e': %.3f",prob/36000);
}