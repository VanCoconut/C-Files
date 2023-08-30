#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 5

int linearSearch_ric(const int a[],int key, size_t size);

int main(void){

    int a[SIZE];

    //genera valori a caso per l'array
    
    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {

        a[i] = 1 + rand() % 5;
        } 

    printf("Immetti l'elemento da cercare:\n");
    
    int searchKey;
    scanf("%d", &searchKey);

    size_t index = linearSearch_ric(a, searchKey, SIZE);   

    if (index != -1)
    {
        printf("La posizione della chiave e': %d\n", linearSearch_ric(a, searchKey, SIZE));
    }else
    {
        puts("Chiave non trovata");
    }
}
    int linearSearch_ric(const int a[],int key, size_t size){

        if(size==0){
            if (a[0]==key)
            {
                return size;
            }
            
        } else
        {
            if (a[size==key])
            {
                return size;
            }else
            {
                return linearSearch_ric(a,key,size-1);
            }           
            
        }     


    }