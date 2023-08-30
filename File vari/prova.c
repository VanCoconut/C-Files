#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct giocatore
{
    char nome[10];
    char segno;
};
typedef struct giocatore Giocatore;

int main(){

    Giocatore g1,g2;

    char griglia[5][5]={0};

    FILE *fp;
    char *turno;
    fp = fopen("C:/Unipa/Programmazione/File.txt/salvataggio.txt", "r");

    fscanf(fp, "%9s %c", g1.nome, &g1.segno);
    printf("Il giocatore %s ha il simbolo %c\n", g1.nome, g1.segno);
    fscanf(fp, "%9s %c", g2.nome, &g2.segno);
    printf("Il giocatore %s ha il simbolo %c\n", g2.nome, g2.segno);

    fscanf(fp, "%s", &turno);   

    if (strcmp(&turno, "Luca") == 0)
    {
        puts("E' il turno di Luca");
    }
    else
    {
        puts("E' il turno di Giuseppe");
    }

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            fscanf(fp,"%c",griglia[i][j]);
        }      
    }

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            printf("%c",griglia[i][j]);
        }
    }
}
