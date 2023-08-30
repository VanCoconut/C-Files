#include <stdio.h>
#define  SIZE 10
void bubblesort(unsigned int a[]);

int main (void){ 
    
int a[SIZE]={1,2,3,4,5,6,7,8,9,10};

bubblesort(a);
    for (size_t i = 0; i < SIZE; i++)
    {
    printf("%4d", a[i]);
    }
}
void bubblesort (unsigned int a[]){

    for (size_t i = 0; i < SIZE; ++i){
        
        for (size_t j = 0; j < SIZE - 1; ++j){
            
            if (a[j]>a[j+1]){
               
                unsigned int hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
                
            }
            if (a[10] < a[9])
            {
                break;
            }
        }
        
    }
    
}