/*Non e' possibile aggiungere ulteriori librerie rispetto a quelle fornite*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct citta {
    /*Definire la struttura*/
};
typedef struct citta Citta;

struct lista {
    /*Definire la struttura*/
};
typedef struct lista Lista;

//Funzioni opzionali
Lista* crealista(FILE*);
void stampaLista(Lista*);
int contaElementi(Lista*);
Lista* pulisciLista(Lista*);

//Funzioni obbligatorie
size_t numeroRighe(FILE*);
void infoAbitanti(Lista*, int*, int, int);
int stampaSuFile(Lista*);
int cercaInLista(Lista **);
Lista* inMaiuscolo(Lista*);
Lista* ordinaPerAbitanti(Lista*, size_t);

int main(){
    /*Completare il main inserendo le opportune istruzioni per l'accesso e la chiusura del file*/
    return 0;
}