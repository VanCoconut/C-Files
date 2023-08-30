#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct coda
{
    size_t time;
    struct coda *next;
};

typedef struct coda Coda;

void enqueue(Coda **,Coda **,size_t);
size_t dequeue(Coda **,Coda **);

int main(){

    size_t tempo;
    size_t servizio;
    size_t counter;
    size_t giorno=720;
    Coda *head=NULL;
    Coda *tail=NULL;    

    srand(time(NULL));

    for (size_t i = 0; i < giorno; i++)
    {
        tempo = 1 + rand() % 4;        
        enqueue(&head,&tail,tempo);
        servizio = 1 + rand() % 4;
        counter=tempo+servizio;
    }
    
    



}