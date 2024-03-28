#include <stdio.h>

struct persona {
    char nome[20];
    char cognome[20];
    int eta;
};
typedef struct persona Persona;

Persona get_youngest(Persona persone[], int num_persone);

int main(void){
    /* dichiariamo un puntatore a FILE */
    FILE *file;
    int num_persone;
    int i;

    /* apriamo il file in sola lettura */
    file = fopen("C:/Unipa/Programmazione/File.txt/persone.txt", "r");

    /* controlliamo che non si siano verificati errori */
    if (file != NULL) {
        /* leggiamo il numero di persone presenti nel file (prima riga) */
        fscanf(file, "%d", &num_persone);

        /* dichiariamo un array che conterrà i dati delle persone */
        Persona persone[num_persone];

        /* per ciascuna delle righe rimanenti (da 0 a num_persone - 1) */
        for (i = 0; i < num_persone; i++) {
            /* dichiariamo una variabile temporanea Persona */
            Persona persona_corrente;

            /* leggiamo nome, cognome ed età dal file e li salviamo nella
               variabile temporanea persona_corrente */
            fscanf(file, "%s %s %d", persona_corrente.nome, persona_corrente.cognome, &persona_corrente.eta);

            /* memorizziamo persona_corrente nell'array, in posizione i */
            persone[i] = persona_corrente;
        }

        /* chiudiamo il file */
        fclose(file);

        /* calcoliamo la persona più giovane */
        Persona youngest = get_youngest(persone, num_persone);
        printf("La persona piu giovane e %s %s (%d anni).\n", youngest.nome, youngest.cognome, youngest.eta);
    }

    return 0;
}

Persona get_youngest(Persona persone[], int num_persone)
{
    /* all'inizio supponiamo che la persona più giovane sia la prima dell'array */
    Persona youngest = persone[0];
    int i;

    /* scorriamo il resto dell'array... */
    for (i = 1; i < num_persone; i++) {
        /* se troviamo una persona più giovane di youngest, aggiorniamo youngest */
        if (persone[i].eta < youngest.eta) {
            youngest = persone[i];
        }
    }
    return youngest;
}
