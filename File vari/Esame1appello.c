#include <stdio.h>
#include <string.h>

struct squadra
{
    char nome[20];
    int vittorie,sconfitte,pareggi;
};

typedef struct squadra Squadra;

// FUNZIONI OPZIONALI

size_t nuemro_righe(FILE *);
void inizializza_array(FILE *, Squadra []);
void stampa_squadre(Squadra [], size_t);

//FUNZIONI OBBLIGATORI  

void vincitore_perdente(Squadra [],size_t,Squadra *,Squadra *);
void partite_giocate(Squadra [],size_t,char[]);
void squadra_maiuscole(Squadra *,size_t);
void ordina(Squadra [],size_t);

int main(){

    FILE *fp = fopen("C:/Unipa/Programmazione/File.txt/classifica.txt","r");
    Squadra squadre[19];
    //printf("Ci sono %d righe",numero_righe(fp));
    inizializza_array(fp,squadre);
    puts("\nClassifica\n");
    stampa_squadre(squadre,20);    
    ordina(squadre, 20);
    puts("\nClassifica ordinata\n");
    stampa_squadre(squadre, 20);
    Squadra vincitore;
    Squadra perdente;
    vincitore_perdente(squadre, 20, &vincitore, &perdente);
    printf("\nVINCITORE: %s, PERDENTE: %s\n", vincitore.nome, perdente.nome);
    partite_giocate(squadre, 20, "C:/Unipa/Programmazione/File.txt/classifica_partite.txt");
    printf("File classifica_partite.txt creato\n\n");
    squadra_maiuscole(squadre,20);
    stampa_squadre(squadre, 20);
}

size_t numero_righe(FILE *fp)
{
    Squadra s;
    size_t counter = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s %d %d %d", s.nome, &s.vittorie, &s.sconfitte, &s.pareggi);
        counter++;
    }
    return counter;
}

void inizializza_array(FILE *fp, Squadra squadre[])
{
    rewind(fp);
    char nome[20];
    unsigned int vittorie;
    unsigned int sconfitte;
    unsigned int pareggi;

    for (size_t i = 0; i < 20; i++)
    {
        fscanf(fp, "%s %d %d %d", squadre[i].nome, &squadre[i].vittorie, &squadre[i].sconfitte, &squadre[i].pareggi);
    }
}

void stampa_squadre(Squadra squadre[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {        
        printf("%s %d %d %d\n", squadre[i].nome, squadre[i].vittorie, squadre[i].sconfitte, squadre[i].pareggi);
    }
}

void vincitore_perdente(Squadra squadre[], size_t n, Squadra *v, Squadra *p)
{
    int max = 0;
    int min = 200;    
    int index_max, index_min;

    for (size_t i = 0; i < n; i++)
    {
        int punteggio_squadra = squadre[i].vittorie * 3 + squadre[i].pareggi * 1;
        if (punteggio_squadra>max)
        {
            index_max=i;
            max=punteggio_squadra;
        }else
        {
            index_min=i;
            min=punteggio_squadra;
        }              
    }
    *v = squadre[index_max];
    *p = squadre[index_min];
}

void ordina(Squadra squadre[], size_t n)
{
    unsigned int punteggio_squadra_1;
    unsigned int punteggio_squadra_2;

    for (unsigned int j = 0; j < n; ++j)
    {
        for (unsigned int i = 0; i < n - 1; ++i)
        {
            punteggio_squadra_1 = squadre[i].vittorie * 3 + squadre[i].pareggi * 1;
            punteggio_squadra_2 = squadre[i+1].vittorie * 3 + squadre[i+1].pareggi * 1;
            if (punteggio_squadra_1 < punteggio_squadra_2)
            {
                Squadra tmp = squadre[i];
                squadre[i] = squadre[i + 1];
                squadre[i + 1] = tmp;
            }
        }
    }
}

void partite_giocate(Squadra squadre[], size_t n, char filename[100])
{
    FILE *cp = fopen(filename, "w");
    for (size_t i = 0; i < 20; i++)
    {
        int num_partite = squadre[i].vittorie + squadre[i].sconfitte + squadre[i].pareggi;
        fprintf(cp, "%s %d\n", squadre[i].nome, num_partite);
    }
    fclose(cp);
}

void squadra_maiuscole(Squadra *s, size_t n){
    
   
}