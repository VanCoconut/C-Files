#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct coda
{
    int data;
    struct coda *Ptr;    
};

typedef struct coda Coda;
typedef Coda *CodaPtr;


void enqueue(CodaPtr *headPtr,CodaPtr *tailPtr,char value){

    CodaPtr newPtr= malloc(sizeof(CodaPtr));

    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->Ptr= NULL;

        if (isEmpty(*headPtr))
        {
            *headPtr = newPtr;
        }
        else
        {
            (*tailPtr)->Ptr = newPtr;
        }
        *tailPtr = newPtr;
    }else
    { 
        printf("Errore\n");
    }    
}

char dequeue(CodaPtr *headPtr, CodaPtr *tailPtr){

    char value=(*headPtr)->data;
    CodaPtr temp = *headPtr;
    *headPtr= (*headPtr)->Ptr;

    if (*headPtr==NULL)
    {
        *tailPtr=NULL;
    }
    free(temp);
    return value; 

}

int isEmpty(CodaPtr headPtr){

    return headPtr==NULL;

}