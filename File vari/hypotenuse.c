#include <stdio.h>
#include <math.h>

double hypotenuse(double c1, double c2);

int main(){

    double cateto1,cateto2;

    printf("Digitare i valori dei due cateti sepaprati da uno spazio\n");

    scanf("%lf%lf",&cateto1,&cateto2);

    printf("Il valore dll'ipotenusa e': %f",hypotenuse(cateto1,cateto2));
    
}

double hypotenuse(double c1, double c2){

    return sqrt(c1*c1+c2*c2);
    
}
