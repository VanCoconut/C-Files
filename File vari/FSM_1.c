#include <stdio.h>
#include <math.h>

int main(void)
{

    char z;
    double e, b, i, c, d, n, m, f, r, s, v, g, h, k, l, w,p,pi;

    s = pow(10, -12);            //potenze
    v = pow(10, 7);              //potenze
    b = 500 * s;                  //T(setup)
    c = 200 * s;                 //tau
    d = 0.5;                     //(N)
    n = 150 * s;                 //T(0)
    m = 3.1415926535897 * v * v; //pi
    pi = 3.1415926535897 *v;     // secondi in pi in 1 anno
    h = pow(10, -9);
    w = pow(10, 9);

    for (i = 0.00; i < 10.00; i += 0.01)
    {
        r = (i*h  - b) / c;
        e = pow(2.718281828459, r);

        double MTBF = (i * e) / (d * n);
        printf("MTBF = %f", MTBF);
        /* if(MTBF==1314000){
            printf("MTBF = %f",e);
            break;
        } */
    }
    
    /*i= w;

    r = (i * h - b) / c;
    e = pow(2.718281828459, r);
   

    double MTBF = (i * e ) / (d*n); 

    MTBF = 50*pi; 

    p = 1/(MTBF);

    printf("Il valore di MTBF e': %.2f\n\n",MTBF);

    printf("Il valore di P(errore) e': %.4f * 10^-7", p*v); */
}
