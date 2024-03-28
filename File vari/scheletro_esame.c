#include <stdio.h>
#include <string.h>

struct studente {
    /*Definire struttura*/
    int matricola;
    char nome[15];
    char cognome[15];
    int anno;
    char sigla[2];
};
typedef struct studente Studente;

/*Funzioni opzionali*/
int inizializza_array(const char filename[], Studente studenti[]);
void stampa_studenti(size_t n, Studente studenti[]);
size_t my_strlen(char stringa[]); 

/*Funzioni obbligatorie*/
int numero_regolari(size_t anno, size_t n, Studente studenti[]);
int cerca_omonimi(size_t n, Studente studenti[], Studente studente, Studente *omonimo);
int nome_piu_lungo_ricorsivo(size_t n, Studente studenti[], int max);
int separa_iscritti(const char f1[], const char f2[], size_t n, Studente studenti[]);

int main(){
    /*Definire il main*/
}

int numero_regolari(size_t anno, size_t n, Studente studenti[])
{
    int contatore=0;
    if (anno >= 1 && anno <= 5)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (studenti[i].anno == anno)
            {
                contatore++;
            }
        }
        return contatore; 
    }
    else
    {
        return -1;
    }
}

int cerca_omonimi(size_t n, Studente studenti[], Studente studente, Studente *omonimo){

    int counter=0;  

        for (size_t i = 0; i < n; i++)
        {
            if (studente.nome==studenti[i].nome)
            {
                if (studente.cognome==studenti[i].cognome)
                {
                    continue;                    
                }                
                counter++;
                omonimo=&studente;
            }
        }        
        return counter;
}

int nome_piu_lungo_ricorsivo(size_t n, Studente studenti[], int max)
{    
    char nome[10];
    int lungezza1;
    int lunghezza2;
    lungezza1 = strlen(studenti[n].nome);
    lunghezza2 = strlen(nome);
    if (lungezza1 == lunghezza2)
    {
        max = lungezza1;
    }
    if (lungezza1 > lunghezza2)
    {
        n++; 
        int numero_char;
        numero_char = lungezza1;
        max = numero_char;
    }
    if (lungezza1 < lunghezza2 && lunghezza2 == 0)
    {
        return max;
    }

    return nome_piu_lungo_ricorsivo(n, &studenti[n], max);
}

int separa_iscritti(const char f1[], const char f2[], size_t n, Studente studenti[]){

    f1="f1.txt";
    f2="f2.txt";

    FILE *Ptr1;
    FILE *Ptr2;

    if ((Ptr1 = fopen(f1, "w")) == NULL)
    {
        puts("Il file non puo essere aperto");
        return 0;
    }

    if ((Ptr2 = fopen(f2, "w")) == NULL)
    {
        puts("Il file non puo essere aperto");
        return 0;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (studenti[i].sigla=="RG")
        {
            fprintf(Ptr1, "%d %s %s %d %s", studenti[i].matricola, studenti[i].anno, studenti[i].cognome, studenti[i].anno, studenti[i].sigla);
        }
        if (studenti[i].sigla == "FC")
        {
            fprintf(Ptr2, "%d %s %s %d %s", studenti[i].matricola, studenti[i].anno, studenti[i].cognome, studenti[i].anno, studenti[i].sigla);
        }    
    }
    puts("File scritti");
    fclose(Ptr1);
    fclose(Ptr2);
    return 1;
}

void stampa_studenti(size_t n, Studente studenti[]){

    for (size_t i = 0; i < n; i++)
    {
        printf("%d %s %s %d %s\n", studenti[i].matricola, studenti[i].nome, studenti[i].cognome, studenti[i].anno, studenti[i].sigla);
    }   

}

int inizializza_array(const char filename[], Studente studenti[]){

    filename="esame.txt";

    FILE *Ptr;

    if ((Ptr = fopen(filename, "r")) == NULL)
    {
        puts("Il file non puo essere aperto");
        return 0;
    }
    else
    {
        
            for (size_t i = 0; !feof(Ptr); i++)
            {
                fscanf(Ptr, "%d %s %s %d %s", &studenti[i].matricola, studenti[i].nome, studenti[i].cognome, &studenti[i].anno, studenti[i].sigla);
            }       
              
    }
    fclose(Ptr);
    return 1;    
}