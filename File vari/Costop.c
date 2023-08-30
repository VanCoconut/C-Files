#include <stdio.h>

float calculateChargers(float t);

int main(void){

    printf("%s%10s%10s\n","Car","Hours","Charge");
        
    float time=1.5;

    float a=calculateChargers(time);

    printf("1%10.2f%10.2f\n",time,a);
    
    time=4;

    float b=calculateChargers(time);

    printf("2%10.2f%10.2f\n", time, b);

    time=24;

    float c=calculateChargers(time);

    printf("3%10.2f%10.2f\n", time, c);

    /*float toth=time     si dovrebbero cambaire le variabili time 

    printf("%s%10.2f%10.2f","TOTAL",toth,totc)*/
}

float calculateChargers(float t){

    float cost=2;

    if (t>3 && t<24)
    {
        for (size_t i = 3; i < t; i++)
        {
            cost=cost+0.5;
        }        
    }else if (t==24)
    {
        cost=10;
    }
    
        
    return cost; 
    
    
}
