#include <stdio.h>   //non funziona

int MCD(int,int);

int main(void){

    int x,y;

    printf("Inserire due numeri separati dallo spazio\n");
    scanf("%d%d",&x,&y);

    printf("Il MCD e': %d",MCD(x,y));
}


int MCD(int a,int b){

    int r,t;

    if (a%b==0)
    {
        return b;
    }

    while (r==0)
    {        
        b=a/b;          
        r=a%b;
        if (r==0)
        {
            break;           
        }
       
        a = b;
        b = r;
        t = r;
    }
    return t;
    
}