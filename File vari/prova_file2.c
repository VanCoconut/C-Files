#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[10];
    char cognome[20];
    size_t numero;
} Voce;

 struct lista
{
    Voce voce;
    struct lista *next;
};
typedef struct lista Lista;

Lista *creaLista();
void stampLista(Lista *lista);
void stampaVoce(Voce rubrica);
void cercaLista(Lista *lista);

int main(){

    Lista *lista=NULL;

    lista=creaLista();
    stampaLista(lista);
    cercaLista(lista);
}

Lista *creaLista()
{

    Lista *head = NULL;
    Lista *tmp = NULL;

    FILE *fp = fopen("C:/Unipa/Programmazione/File.txt/voci_rubrica.txt", "r");

    if (fp != NULL)
    {
        Voce rubrica;

        while (fscanf(fp, "%9s %19s %d", rubrica.nome, rubrica.cognome, &rubrica.numero) > 0)
        {
            if (head == NULL)
            {
                head = malloc(sizeof(Lista));
                head->voce = rubrica;
                head->next = NULL;
            }
            else
            {
                tmp = malloc(sizeof(Lista));
                tmp->voce = rubrica;
                tmp->next = head;
                head = tmp;
            }
        }
        fclose(fp);
    }
    return head;
}

void stampLista(Lista *lista)
{

    if (lista == NULL)
    {
        puts("Lista vuota");
    }

    while (lista != NULL)
    {
        //stampaVoce(lista->voce);
        printf("%s %s %d",lista->voce.nome,lista->voce.cognome,lista->voce.numero);
        lista = lista->next;
    }
}

void stampaVoce(Voce rubrica)
{
    printf("%s %s %d", rubrica.nome, rubrica.cognome, rubrica.numero);
}

void cercaLista(Lista *lista)
{

    char nome[10];
    char cognome[20];
    puts("Inserire nome");
    scanf("%9s", nome);
    puts("Inserire cognome");
    scanf("%19s", cognome);

    while (lista != NULL)
    {
        if (strcmp((lista->voce).nome, nome) == 0 && strcmp((lista->voce).cognome, cognome) == 0)
        {
            puts("Voce trovata");
            stampaVoce(lista->voce);
        }
        lista = lista->next;
    }

    puts("Voce non trovata");
}
