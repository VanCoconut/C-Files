#include <stdio.h>
#include <math.h>

int arrotodatore(float);

int main(void){

    float n=0;

    printf("Enter a number\n");

    scanf("%f",&n);

    int x=arrotodatore(n);

    printf("Number in: %.2f \t\t Number out: %d",n,x);

}

int arrotodatore(float a){

    int x=floor(a+.5);
    return x;
}