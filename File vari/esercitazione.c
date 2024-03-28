#include <stdio.h>
#include <math.h>

int main(void){

    int potenza(int x, int n);

    int f=1;
    
    for(i=1, i<=n, ++i){

        f *= x; 
    }
    return f;
}


    //prototipo + implementazione: posizionato prima del main
    double base(int xa, int ya, int xb, int yb) {
        int diff_x = xa-xb;
        int diff_y = ya-yb;
        int pot_x = potenza(diff_x, 2);
        int pot_y = potenza(diff_y, 2);
        int somma = pot_x + pot_y;
        double out = sqrt(somma);

    }


    //prototipo
    double base(int xa, int xb, int ya, int yb);
    //implementazione: dove vogliamo ma dopo il prototipo
    double base(int xa, int ya, int xb, int yb) {
    return sqrt(potenza((xa - xb), 2) + potenza((ya - yb), 2));
}

//altezza triangolo

A(xa, ya)
B(xb, yb)
C(xc, yc)

(x-xa)/(xb-xa) = (y-ya)/(yb-ya)

ax+by+c=0

xb-xa=0 => x-xa=0 ------- a=1 b=0 c=-xa
yb-ya=0 => y-ya=0 ------- a=0 b=1 c=-ya

xb-xa!=0 && yb-ya!=0 => [(yb-ya)/(xb-xa)](x-xa) - (y-ya) = 0

[(yb-ya)/(xb-xa)]x - [(yb-ya)/(xb-xa)]xa -y +ya = 0

a = [(yb-ya)/(xb-xa)]
b = -1
c = ya - [(yb-ya)/(xb-xa)]xa

//calcolare l'altezza

double getHeight(double a, double b, double c, int x, int y){
    return (a*x + b*y + c)/sqrt(potenza(a,2) + potenza (b,2));
}