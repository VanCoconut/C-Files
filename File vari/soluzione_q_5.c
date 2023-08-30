#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Deinisco una struttura persona*/
struct persona
{
    char nome[20];
    char cognome[20];
    char numero[10];
};
typedef struct persona Persona;

/*Definisco una struttura per creare la lista*/
struct node
{
    Persona p;
    struct node *next;
};
typedef struct node Node;

void printPersona(Persona p)
{
    printf("Nome: %s, Cognome: %s, Numero: %s\n", p.nome, p.cognome, p.numero);
    return;
}

Node *clearList(Node *node)
{
    Node *tmp;
    while (node != NULL)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    printf("Lista svuotata\n");
    return node;
}

void stampa(Node *node)
{
    if (node == NULL)
    {
        printf("La lista è vuota\n");
        return;
    }

    while (node != NULL)
    {
        printPersona(node->p);
        node = node->next;
    }
    return;
}

int conteggio(Node *node)
{
    int i = 0;
    while (node != NULL)
    {
        ++i;
        node = node->next;
    }
    return i;
}

int ricerca(Node *node)
{
    char nome[20];
    char cognome[20];
    printf("Inserire nome da cercare\n");
    scanf("%s", nome);
    printf("Inserire cognome da cercare\n");
    scanf("%s", cognome);
    int index = -1, i = 0;
    while (node != NULL)
    {
        if (strcmp((node->p).nome, nome) == 0 && strcmp((node->p).cognome, cognome) == 0)
        {
            printPersona(node->p);
            index = i;
            return index;
        }
        ++i;
        node = node->next;
    }
    printf("Voce non presente in rubrica\n");
    return -1;
}

void aggiornamento(Node *node)
{
    char nome[20];
    char cognome[20];
    char numero[10];
    printf("Inserire nome da cercare\n");
    scanf("%s", nome);
    printf("Inserire cognome da cercare\n");
    scanf("%s", cognome);
    printf("Inserire il nuovo numero di telefono\n");
    scanf("%s", numero);
    while (node != NULL)
    {
        if (strcmp((node->p).nome, nome) == 0 && strcmp((node->p).cognome, cognome) == 0)
        {
            printPersona(node->p);
            strcpy(node->p.numero, numero);
            printf("Numero aggiornato correttamente\n");
            return;
        }
        node = node->next;
    }
    printf("Voce non presente in rubrica\n");
    return;
}

Node *inizializza()
{

    Node *list = NULL;
    Node *node = NULL;

    /* apriamo il file in sola lettura */
    FILE *file = fopen("C:/Unipa/Programmazione/File.txt/voci_rubrica.txt", "r");

    /* controlliamo che non si siano verificati errori */
    if (file != NULL)
    {
        Persona persona;
        int i = 0;
        while (fscanf(file, "%s %s %s", persona.nome, persona.cognome, persona.numero) > 0)
        {
            /*Se sto leggendo la prima riga creo la testa della lista*/
            if (list == NULL)
            {
                list = (Node *)malloc(sizeof(Node));
                list->p = persona;
                list->next = NULL;
            }
            else
            {
                node = (Node *)malloc(sizeof(Node));
                node->p = persona;
                node->next = list;
                list = node;
            }
        }
        /* chiudiamo il file */
        fclose(file);
    }
    return list;
}

int main()
{

    Node *list = NULL;
    int option;
    char *temp;

    /* Display Menu */
    while (1)
    {

        printf("\n ******************************************\n");
        printf("\n *  Linked list operations:               *\n");
        printf("\n *    0. Inizializza                      *\n");
        printf("\n *    1. Stampa                           *\n");
        printf("\n *    2. Conta                            *\n");
        printf("\n *    3. Ricerca                          *\n");
        printf("\n *    4. Aggiorna                         *\n");
        printf("\n *    5. Svuota                           *\n");
        printf("\n *    6. Esci                             *\n");
        printf("\n ******************************************\n");
        printf("\n Choose an option [0-6] : ");
        if (scanf("%d", &option) != 1)
        {
            printf(" *Error: Invalid input. Press try again.\n");
            scanf("%s", temp); /*this will clear the input buffer */
            continue;
        }

        switch (option)
        {
        case 0:
            list = inizializza();
            break;

        case 1:
            stampa(list);
            break;

        case 2:
            printf("Il numero di elementi nella lista è: %d\n", conteggio(list));
            break;

        case 3:
            ricerca(list);
            break;

        case 4:
            aggiornamento(list);
            break;

        case 5:
            list = clearList(list);
            break;

        case 6:
            return 0;

        default:
            printf("Invalid Option. Please Try again.");
            break;
        } /* End of Switch */
    }     /* End of While */

}