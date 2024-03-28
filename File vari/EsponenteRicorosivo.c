#include <stdio.h>

int esp(int,int);

int main(void){

    int a,b; a=2; b=3;

    //printf("inserire base ed esponente\n");
    //scanf("%d%d",&a,&b);

    printf("%d elevato a %d = %d",a,b,esp(a,b));
}

int esp(int a, int b){

    if (b==0)
    {
        return 1;
    }else if (b==1)
    {
        return a;
    }else
    {
       return esp(a,b)+esp(a,b-1);
    }
    
    
    


}