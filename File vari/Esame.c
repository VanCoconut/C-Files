#include <stdio.h>
#include <string.h>

#define N 5

struct giocatore {
    char nome[10];
    char segno;
};
typedef struct giocatore Giocatore;

/*Funzioni opzionali*/
void stampa_griglia(size_t n, char griglia[][]);
int conta_celle_vuote(size_t n, char griglia[][]);
void mossa(Giocatore g, size_t n, char griglia[][]);

/*Funzioni obbligatorie*/
int carica_partita(Giocatore* , Giocatore* g2, size_t n, char griglia[][]);
int colonne_righe(Giocatore , size_t n, char griglia[][]);
int diag_secondaria(size_t , char griglia[][], Giocatore g);
int conta_segni(Giocatore , size_t , size_t , size_t n, char griglia[][]);

int main(){
    /*Definire il main*/
    
    Giocatore g1;    
    Giocatore g2;
    char griglia[N][N];
    int c = carica_partita(&g1, &g2, N, griglia);
    

    if (c == 0)
    {
        printf("E' il turno di Giuseppe");
    }else
    {
        printf("E' il turno di Luca");
    }

    int b=conta_celle_vuote(N,griglia);
    printf("\nNumero celle vuote : %d\n",b);
    //sbaglaito
    /*char simbolo='X';
    g1.segno=simbolo;
    printf("\n%s\n",g1.segno);
    

    size_t b = 0;     
    b = conta_segni(g1, N, N, b, griglia);
    printf("\nIl numero di %c e' %d\n", g1.segno, b);
   // b = conta_segni(g2, N, N, b, griglia);
   // printf("\nIl numero di %c è %d\n", g2.segno, b);    */
    
}

int carica_partita(Giocatore *g1, Giocatore *g2, size_t n, char griglia[][n]){

    FILE *fp;
    char *turno;
    int c;
    fp = fopen("C:/Unipa/Programmazione/File.txt/salvataggio.txt", "r");

    fscanf(fp, "%9s %c", g1->nome, &g1->segno);
    printf("Il giocatore %s ha il simbolo %c\n", g1->nome, g1->segno);
    fscanf(fp, "%9s %c", g2->nome, &g2->segno);
    printf("Il giocatore %s ha il simbolo %c\n", g2->nome, g2->segno);

    fscanf(fp, "%s", &turno);

    

    if (strcmp(&turno,"Luca")==0)
    {
        c=1;
    }else
    {
        c=0;
    }
     for (size_t k = 0; k < 5; k++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                fscanf(fp, "%s \n", &griglia[k][j]);               
            }            
        }
    stampa_griglia(N,griglia);
    return c;
}

int colonne_righe(Giocatore g, size_t n, char griglia[][n]){    

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; i < n; i++)
        {
            char segno=griglia[i][j];
            if (griglia[n - i][n - j] == griglia[n - i][n - j + 1] && griglia[n - i][n - j + 1] == griglia[n - i][n - j + 2])
            {
                if (strcmp(griglia[n - i][n - j],&g.segno)==0)
                {           
                    printf("Il giocatore %s ha vinto",g.nome);         
                    return 1;
                } 
                return 1;                               
            }
            if (griglia[n - i][n - j] == griglia[n - i + 1][n - j] && griglia[n - i + 1][n - j] == griglia[n - i + 2][n - j])
            {
                if (strcmp(griglia[n - i][n - j], &g.segno)==0)
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

int diag_secondaria(size_t n, char griglia[][n], Giocatore g){

    int counter=0;

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 4; j >= 0; j--)
        {
            if ((i+j)==6)
            {
                int counter;
                char *segno = &griglia[i][j];
                if(strcmp(*segno, &g.segno) == 0)
                {
                    counter++;
                }                
            }         
        }
    }
    return counter;
}

void stampa_griglia(size_t n, char griglia[][n])
{

    puts("La tabella e'");

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            printf("%c ", griglia[i][j]);
        }
        puts("");
    }
}

int conta_celle_vuote(size_t n, char griglia[][n])
{

    int contatore=0;
    char l='e';

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (griglia[i][j] == l)
            {
                contatore++;
            }
        }
    }

    return contatore;
}
/*
int conta_celle_vuote(size_t n, char griglia[][n])
{
    char vuoto = 'e';
    int count = 0;
    for (size_t k = 0; k < N; k++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (griglia[k][j] == vuoto)
            {
                count++;
            }
        }
    }
    return count;
}*/

    void mossa(Giocatore g, size_t n, char griglia[][n])
    {

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; i < n; i++)
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

    int conta_segni(Giocatore g, size_t r, size_t c, size_t b, char griglia[][N]) //sbaglaito
    {
        char simbolo = 'X';
        g.segno = simbolo;

        if (c <= 5)
        {
            if (griglia[r][c] == g.segno)
            {
                b++;
            }
            r--;
        }
        if (r == 0)
        {
            c--;
            r = 5;
        }

        else
        {
            return conta_segni(g, r, c, b, griglia);
        }
        return b;
    }