#include <stdio.h>

typedef struct
{
    char matricola[7];
    int esami_sostenuti;
    int voti[20];
}Studente;

Studente crea_studente(char *matricola);
void nuova_materia(Studente *studente, int voto);
float calc_media(Studente studente);


int main(){
    Studente studente;
    char matricola[7];
    int num_esami;
    float media;

    puts("Inserie matricola");
    scanf("%s",&matricola);

    studente=crea_studente(matricola);

    puts("Iserire numero di materie date");
    scanf("%d",&num_esami);

    for (size_t i = 0; i < num_esami; i++)
    {
        int voto;
        printf("Inserire voto della materia %d\n",1+i);
        scanf("%d",voto);

        nuova_materia(&studente,voto);
    }
       
   
}

Studente crea_studente(char *matricola){

    Studente studente;    
    studente.matricola[7]=matricola;
    studente.esami_sostenuti=0;
}

void nuova_materia(Studente *studente, int voto)
{    
    int index = studente->esami_sostenuti;
    studente->voti[index] = voto;
    studente->esami_sostenuti++;
}

float calc_media(Studente studente){

    float media;
    int somma;

    for (size_t i = 0; i < studente.esami_sostenuti; i++)
    {
        somma+=studente.voti[i];         
    }
    media=somma/studente.esami_sostenuti;   
    return media;
}