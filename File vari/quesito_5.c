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
void stampaVoce(Voce );
void cercaLista(Lista *);
void stampaLista(Lista *);
int contaNodi(Lista *);
Lista *pulisciLista(Lista *);
void aggiornaLista(Lista *lista);


int main()
{
    Lista *lista = NULL;
    int scelta = -1;
    char *temp;


    while(1)
    {
        puts("SCegliere un'operazione:");
        puts("*\t 0. CREA LISTA");
        puts("*\t 1. STAMPA LISTA");
        puts("*\t 2. CONTA ELEMENTI NELLA LISTA");
        puts("*\t 3. CERCA ELEMENTI NELLA LISTA");
        puts("*\t 4. AGGIORNA NUEMRO");
        puts("*\t 5. SVUOTA LISTA");
        puts("*\t 6. ESCI");

        if (scanf("%d", &scelta) != 1)
        {
            printf(" *Error: Invalid input. Press try again.\n");
            scanf("%s", temp); /*this will clear the input buffer */
            continue;
        }
        switch (scelta)
        {
        case 0:
            lista = creaLista();
            break;
        case 1:
            stampLista(lista);
            break;
        case 2:
            printf("Ci sono %d nodi\n", contaNodi(lista));
            break;
        case 3:
            cercaLista(lista);
            break;
        case 4:
            aggiornaLista(lista);
            break;
        case 5:
            lista = pulisciLista(lista);
            stampLista(lista);
            break;
        default:
            puts("END");
            return 0;
        }
    }
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

void stampLista(Lista *l)
{
    if (l==NULL)
    {
        puts("Lista vuota");
    }
    while (l != NULL)
    {
        printf("%s %s %d\n", l->voce.nome, l->voce.cognome, l->voce.numero);
        l = l->next;
    }
    printf("\n");
    return;
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
        return;
    }
    puts("Voce non trovata");
}

int contaNodi(Lista *l)
{

    int i = 0;
    while (l!=NULL)
    {        
        l=l->next;
        i++;
    }
    
    return i;    
}

Lista *pulisciLista(Lista *l)
{
    
    Lista *tmp;
    while (l!=NULL)
    {
        tmp=l;
        l=l->next;
        free(tmp);
    }
    puts("Lista svuotata");
    return l;
    
}

void aggiornaLista(Lista *lista)
{
    char nome[10];
    char cognome[20];
    int numero;
    puts("Inserire nome");
    scanf("%9s",nome);
    puts("Inserire cognome");
    scanf("%19s",cognome);
    

    while(lista!=NULL)
    {
        if (strcmp((lista->voce).nome, nome) == 0 && strcmp((lista->voce).cognome, cognome) == 0)
        {
            puts("Inserire numero aggiornato");
            scanf("%d", &numero);
            lista->voce.numero=numero;
            puts("Numero aggiornato");         
            return;
        }
        lista=lista->next;
    }
    printf("Voce non presente in rubrica\n");
    return;    
}



