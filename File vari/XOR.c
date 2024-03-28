#include <stdio.h>

int main(){

    xor_array(97);
    

    
}

void xor_array(int n){

    int array[4]={0,0,0,0};

    for (size_t i = 0; i < 5; i++)
    {
        array[i]=i*60;
        array[i] = array[i] ^ n;
        printf("Il valore e': %d\n",array[i]);
    }
      
}