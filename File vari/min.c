#include <stdio.h>

float min(float,float,float);

int main(void){
    
    float a,b,c;
    
    printf("Inserire 3 numeri\n"); 
    scanf("%f%f%f", &a, &b, &c);

    printf("Il numero piu' piccolo e': %.2f",min(a,b,c));
}


float min(float a, float b, float c){

   if (a>b)
   {
       a=b;
   }if (a>c)
   {
       a=c;
   }

   return a;
}