
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    struct squadra
{
    char nome[15];
    unsigned int vittorie;
    unsigned int sconfitte;
    unsigned int pareggi;
};
typedef struct squadra Squadra;

size_t numero_righe(FILE *);
void inizializza_array(FILE *, Squadra[]);
void stampa_squadre(Squadra[], size_t);

void vincitore_perdente(Squadra[], size_t, Squadra *, Squadra *);
void partite_giocate(Squadra[], size_t, char[]);
void squadre_maiuscole(Squadra *, size_t);
void ordina(Squadra[], size_t);

int main(void)
{
    FILE *fp = fopen("CLASSIFICA.TXT", "r");

    printf("Numero righe %lu\n", numero_righe(fp));

    Squadra *squadre = malloc(sizeof(Squadra) * 20);
    inizializza_array(fp, squadre);

    Squadra vincitore;
    Squadra perdente;
    vincitore_perdente(squadre, 20, &vincitore, &perdente);
    printf("VINCITORE: %s, PERDENTE: %s\n\n", vincitore.nome, perdente.nome);

    puts("\nPre-ordinamento:");
    stampa_squadre(squadre, 20);
    ordina(squadre, 20);
    puts("\nPost-ordinamento:");
    stampa_squadre(squadre, 20);

    partite_giocate(squadre, 20, "PartiteGiocate.txt");

    puts("\nMaiuscole:");
    squadre_maiuscole(squadre, 20);
    stampa_squadre(squadre, 20);

    fclose(fp);
    return 0;
}

size_t numero_righe(FILE *fp)
{
    size_t righe = 0;
    char riga[80];

    while (fgets(riga, 79, fp) > 0)
    {
        ++righe;
    }

    return righe;
}

void inizializza_array(FILE *fp, Squadra squadre[])
{
    rewind(fp);
    char nome[15];
    unsigned int vittorie;
    unsigned int sconfitte;
    unsigned int pareggi;

    for (unsigned int i = 0; i < 20; ++i)
    {
        fscanf(fp, "%14s %u %u %u\n", nome, &vittorie, &sconfitte, &pareggi);
        strcpy(squadre[i].nome, nome);
        squadre[i].vittorie = vittorie;
        squadre[i].sconfitte = sconfitte;
        squadre[i].pareggi = pareggi;
    }
    return;
}

void stampa_squadre(Squadra squadre[], size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        printf("Nome squadra %s, vittorie %u, sconfitte %u, pareggi %u\n", squadre[i].nome, squadre[i].vittorie, squadre[i].sconfitte, squadre[i].pareggi);
    }
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
            punteggio_squadra_2 = squadre[i + 1].vittorie * 3 + squadre[i + 1].pareggi * 1;
            if (punteggio_squadra_1 < punteggio_squadra_2)
            {
                Squadra tmp = squadre[i];
                squadre[i] = squadre[i + 1];
                squadre[i + 1] = tmp;
            }
        }
    }
}

void partite_giocate(Squadra squadre[], size_t n, char filename[])
{
    unsigned int numero_partite;
    FILE *fp = fopen(filename, "w");

    for (unsigned int i = 0; i < n; ++i)
    {
        numero_partite = squadre[i].vittorie + squadre[i].sconfitte + squadre[i].pareggi;
        fprintf(fp, "%s %u\n", squadre[i].nome, numero_partite);
    }

    fclose(fp);
}

void vincitore_perdente(Squadra squadre[], size_t n, Squadra *v, Squadra *p)
{
    unsigned int punteggio_max = 0;
    unsigned int punteggio_minimo = 200;
    unsigned int punteggio_squadra;
    size_t index;

    for (size_t i = 0; i < n; ++i)
    {
        punteggio_squadra = squadre[i].vittorie * 3 + squadre[i].pareggi * 1;
        if (punteggio_squadra > punteggio_max)
        {
            index = i;
            punteggio_max = punteggio_squadra;
        }
    }
    *v = squadre[index];

    for (size_t i = 0; i < n; ++i)
    {
        punteggio_squadra = squadre[i].vittorie * 3 + squadre[i].pareggi * 1;
        if (punteggio_squadra < punteggio_minimo)
        {
            index = i;
            punteggio_minimo = punteggio_squadra;
        }
    }
    *p = squadre[index];
}
void squadre_maiuscole(Squadra *squadra, size_t size)
{
    if (size == 0)
    {
        for (unsigned int i = 0; squadra[0].nome[i] != '\0'; ++i)
        {
            if (squadra[0].nome[i] >= 'a' && squadra[0].nome[i] >= 'z')
            {
                squadra[0].nome[i] = squadra[0].nome[i] - 32;
            }
        }
    }
    else
    {
        for (unsigned int i = 0; squadra[size - 1].nome[i] != '\0'; ++i)
        {
            if (squadra[size - 1].nome[i] >= 'a' && squadra[size - 1].nome[i] <= 'z')
            {
                squadra[size - 1].nome[i] = squadra[size - 1].nome[i] - 32;
            }
        }
        squadre_maiuscole(squadra, size - 1);
    }
}


