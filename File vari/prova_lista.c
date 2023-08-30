#include <stdio.h>
#include <stdlib.h>

 typedef struct 
 {
     char data;
     struct Lista *nextPtr;
 }Lista;
 

typedef Lista *ListPtr;

void insert(ListPtr *sPtr, char value);
void printList(ListPtr vPtr);

int main(){
    ListPtr startPtr=NULL;
    char item;
    puts("Inserire un carattere:");
    scanf("%c",&item);
    insert(&startPtr,item);
    printList(startPtr);
    puts("Fine");

}

void insert(ListPtr *sPtr, char value){

    ListPtr newPtr=malloc(sizeof(Lista));

    if (newPtr!=NULL)
    {
        newPtr->data=value;
        newPtr->nextPtr=NULL;

        ListPtr previousPtr=NULL;
        ListPtr currentPtr=*sPtr;

        while (currentPtr!=NULL && value>currentPtr->data)
        {
            previousPtr=currentPtr;
            currentPtr=currentPtr->nextPtr;
        }

        if (previousPtr==NULL)
        {
            newPtr->nextPtr=sPtr;
            *sPtr=newPtr;      
        }else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
        
    }else
    {
        puts("Errore");
    }        


}

void printList(ListPtr vPtr){

    puts("The list is:");
    while (vPtr=!NULL)
    {
        printf("%c --> ",vPtr->data);
        vPtr=vPtr->nextPtr;
    }
    puts("NULL\n");
    
}
