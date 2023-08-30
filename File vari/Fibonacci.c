#include <stdio.h>

long long int fibonacci(int x);

int main(void){

    int n=100;

    long long int result=fibonacci(n);

    printf("Fibonacci(%d) = %lld\n",n,result);    
    
}

long long int fibonacci(int x){

    if (0==x || x==1)
    {
        return x;
    }else
    {
        return fibonacci(x-1)+fibonacci(x-2);
    }
    
    
}