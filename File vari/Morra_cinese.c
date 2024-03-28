#include <stdio.h>
#include <time.h>
#define TRUE 1

typedef struct
{
    int mossa[3];
} Player;

void initMosse(Player *, int);
void mossaComputer(Player *, int);
void mossaGiocatore(Player *, int);
int whoIsWinner(Player *, Player *);

int main()
{

    Player p1, p2;
    int vittorie = 0, sconfitte = 0, tie = 0, mosse = 3;

    while (NULL == 0)
    {
        srand(time(NULL));
        mossaGiocatore(&p1, mosse);
        mossaComputer(&p2, mosse);
        switch (whoIsWinner(&p1, &p2))
        {
        case 0:
            puts("Player wins");
            vittorie++;
            printf("Numero di vittorie: %d\n", vittorie);
            break;
        case 1:
            puts("Computer wins");
            sconfitte++;
            printf("Numero di sconfitte: %d\n", sconfitte);
            break;
        case 2:
            puts("Pari");
            printf("Numero di pari: %d\n", tie);
            break;
        default:
            puts("Errore");
            break;
        }
        if (vittorie == 3)
        {
            break;
        }
        else if (sconfitte == 3)
        {
            break;
        }
    }
}

void mossaGiocatore(Player *p, int n)
{

    int scelta;
    printf("Inserire la scelta: #0=Carta, #1=Forbici, #2=Pietra\n");
    scanf("%d", &scelta);
    for (size_t i = 0; i < n; i++)
    {
        if (scelta == i)
        {
            p->mossa[i] = 1;
        }
        else
        {
            p->mossa[i] = 0;
        }
    }
}

void mossaComputer(Player *p, int n)
{

    int scelta = rand() % 3;
    for (size_t i = 0; i < n; i++)
    {
        if (scelta == i)
        {
            p->mossa[i] = 1;
        }
        else
        {
            p->mossa[i] = 0;
        }
    }

    if (scelta == 0)
    {
        puts("Il computer sceglie Carta");
    }
    else if (scelta == 1)
    {
        puts("Il computer sceglie Forbici");
    }
    else
    {
        puts("Il computer sceglie Pietra");
    }
}

int whoIsWinner(Player *p1, Player *p2)
{

    if ((p1->mossa[i] == 0 && p2->mossa[i] == 2) || p1->mossa[i] > p2->mossa[i])
    {
        return 0;
    }
    else if ((p1->mossa[i] == 2 && p2->mossa[i] == 0) || p2->mossa[i] > p1->mossa[i])
    {
        return 1;
    }
    else if (p1->mossa[i] == p2->mossa[i])
    {
        return 2;
    }
}