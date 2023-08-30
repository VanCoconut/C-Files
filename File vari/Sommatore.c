#include <stdio.h>
#include <math.h>

double sommaProp(int bit, int rit_f);                     //bit = numero di bit,  rit_f = ritardo full adder
double sommaAnt(int bit, int blocchi, int rit_p, int rit_f); // bit = numero di bit, rit_p = ritardo porta a due ingressi,
                                                             //rit_f = ritardo full adder
int main(void){

    int n, bit, blocchi, rit_f, rit_p;

    printf("Calcolare il ritardo di un sommatore a propagazione o ad anticipazione?\nScrivere 1 o 2 sul terminale\n");
    scanf("%d",&n);

    if (n==1)
    {
        printf("Inserire il numero dei bit e il ritardo del full adder\n");
        scanf("%d %d",&bit,&rit_f);
      
        printf("IL ritardo del sommatore a propagazione di riporto ad onda e': %.2f  ps",sommaProp(bit,rit_f));

    }else if (n==2)
    {
        printf("Inserire il numero dei bit,il numero dei blocchi, il ritardo delle singole porte e del full adder\n");
        scanf("%d %d %d %d", &bit, &blocchi, &rit_p, &rit_f);
        printf("IL ritardo del sommatore ad anticipazione di riport e': %.2f  ps", sommaAnt(bit, blocchi, rit_p, rit_f));
    }else
    {
        printf("Errore!\n");
    }
    
    
}

double sommaProp(int bit, int rit_f)
{

    double n = bit * rit_f;

    return n;
}

double sommaAnt(int bit, int blocchi, int rit_p, int rit_f)
{

    double rit_blocco = (bit/blocchi-2)*rit_p;
    double d = (bit / blocchi - 1);
    return rit_p + rit_blocco + d * (2 * rit_p) + blocchi * rit_f;

}
