#include <stdio.h>

int pariDispari(int a);

int main(void){

    int x;

    printf("Inserire un valore, -1 per uscire.\n");
    scanf("%d",&x);

    while (x!=-1)
    {
        pariDispari(x);

        printf("Inserire un valore, -1 per uscire.\n");
        scanf("%d", &x);
        getchar();
    }
    

   
}

int pariDispari(int a){

    int r=a%2;

    if (r==0)
    {
        printf("%d e' pari.\n",a);
    }else
    {
        printf("%d e' disapri.\n",a);
    }
    
    
}



