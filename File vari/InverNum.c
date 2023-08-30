#include <stdio.h>
#define SIZE 7

void printArray(int a[], int size);


int main(){

    int a[SIZE]={1,2,3,4,5,6,7};

    printArray(a, SIZE); 
}

void printArray(int a[],int size){  
    

    if (size==0)
    {
       return;

    }else
    {
       // printf("Il valore di size e': %d\t", size);
        printf("%d\t", a[size-1]);
        printArray(a, size - 1);
    }

}