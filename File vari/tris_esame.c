#include <stdio.h>
#include <string.h>

#define N 5

struct giocatore
{
    char nome[10];
    char segno;
};
typedef struct giocatore Giocatore;

/*Funzioni opzionali*/
void stampa_griglia(size_t n, char griglia[][n]);
int conta_celle_vuote(size_t n, char griglia[][n]);
void mossa(Giocatore g, size_t n, char griglia[][n]);

/*Funzioni obbligatorie*/
int carica_partita(Giocatore *g1, Giocatore *g2, size_t n, char griglia[][n]);
int colonne_righe(Giocatore g, size_t n, char griglia[][n]);
int diag_secondaria(size_t n, char griglia[][n], Giocatore g);
int conta_segni(Giocatore g, size_t r, size_t c, size_t n, char griglia[][n]);

int main()
{
    /*Definire il main*/
}

int carica_partita(Giocatore *g1, Giocatore *g2, size_t n, char griglia[][n])
{

    FILE *fp;
    char turno[10];
    fp = fopen("soluzione.txt", "r");

    fscanf(fp, "%9s %c", g1->nome, &g1->segno);
    printf("Il giocatore %s ha il simbolo %c", g1->nome, g1->segno);
    fscanf(fp, "%9s %c", g2->nome, &g2->segno);
    printf("Il giocatore %s ha il simbolo %c", g1->nome, g1->segno);

    fscanf(fp, "%s", turno);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; i < n; i++)
        {
            fscanf(fp, "%c", griglia[i][j]);
        }
    }

    if (strcmp(turno, "Luca") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int colonne_righe(Giocatore g, size_t n, char griglia[][n])
{

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; i < n; i++)
        {
            char segno = griglia[i][j];
            if (griglia[n - i][n - j] == griglia[n - i][n - j + 1] && griglia[n - i][n - j + 1] == griglia[n - i][n - j + 2])
            {
                if (strcmp(griglia[n - i][n - j], g.segno))
                {
                    printf("Il giocatore %s ha vinto", g.nome);
                    return 1;
                }
                return 1;
            }
            if (griglia[n - i][n - j] == griglia[n - i + 1][n - j] && griglia[n - i + 1][n - j] == griglia[n - i + 2][n - j])
            {
                if (strcmp(griglia[n - i][n - j], g.segno))
                {
                    printf("Il giocatore %s ha vinto", g.nome);
                    return 1;
                }
                return 1;
            }
            return 0;
        }
    }
}

void stampa_griglia(size_t n, char griglia[][n])
{

    puts("La tabella e'");

    for (size_t i = 0; i < n; i++)
    {
        for (size_t i = 0; i < n; i++)
        {
            printf("%c\t", griglia[i][j]);
        }
    }
}

int conta_celle_vuote(size_t n, char griglia[][n])
{

    int contatore;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (griglia[i][j] == 'e')
            {
                contatore++;
            }
        }
    }

    return contatore;
}

void mossa(Giocatore g, size_t n, char griglia[][n])
{

    for (size_t i = 0; i < n; i++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (griglia[i][j] == 'e')
            {
                printf("Inserire simbolo");
                char simbolo;
                scanf("%c", &simbolo);
                griglia[i][j] = simbolo;
                return;
            }
        }
    }
}