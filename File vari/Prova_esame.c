#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct citta
{
    char abbr[3];
    char nome[20];
    int abitanti;
};
typedef struct citta Citta;

struct lista
{
    Citta citta;
    struct lista *next;
};
typedef struct lista Lista;

//Funzioni opzionali
Lista *crealista(FILE *);
void stampaLista(Lista *);
int contaElementi(Lista *);
Lista *pulisciLista(Lista *);

//Funzioni obbligatorie
size_t numeroRighe(FILE *);
void infoAbitanti(Lista *, int *, int, int);
int stampaSuFile(Lista *);
int cercaInLista(Lista **);
Lista *inMaiuscolo(Lista *);
Lista *ordinaPerAbitanti(Lista *, size_t);

int main(){

    FILE *ptr;
    
    //nuemro righe
    printf("ci sono %d righe",numeroRighe(ptr));
    //crea lista
    Lista *lista=creaLista(ptr);
    //numero nodi
    printf("ci sono %d nodi", contaNodi(lista));
    //stampa lista
    stampaLista(lista);


    
}

size_t numeroRighe(FILE *fp){

    Citta citta; 
    size_t i=0;       
    fp = fopen("C:/Unipa/Programmazione/File.txt/citta.txt","r");
    while (!feof(fp))
    {
        fscanf(fp,"%2s %19s %d",citta.abbr,citta.nome,&citta.abitanti);
        i++;
    }
    return i;
    
}

Lista *creaLista(FILE *fp)
{

    Lista *head = NULL;
    Lista *tmp = NULL;
    Citta citta;

    while (fscanf(fp, "%2s %19s %d", citta.abbr, citta.nome, &citta.abitanti) > 0)
    {
        if (head == NULL)
        {
            head = malloc(sizeof(Lista));
            head->citta = citta;
            head->next = NULL;
        }
        else
        {
            tmp = malloc(sizeof(Lista));
            tmp->citta = citta;
            tmp->next = head;
            tmp = head;
        }
    }
    return head;
}

int cercaInLista(Lista **l){

    Lista *head=*l;
    char abbr[3];
    char nome[20];

    puts("Inserire abbreviazione");
    scanf("%2s",nome);
    puts("Inserire nome della citta");
    scanf("%19s",nome);

    while (head!=NULL)
    {
        if (strcmp((head->citta).abbr,abbr)==0 && strcmp((head->citta).nome,nome)==0)
        {
            return 0;
        }
        if (strcmp((head->citta).abbr, abbr) == 0 && strcmp((head->citta).nome,nome) != 0)
        {
            return 2;
        }
        head=head->next;       
    }

    puts("Voce non torvata");
    int n;
    puts("Inserire numero abitanti");
    scanf("%d",&n);
    Citta citta;
    strcpy(citta.abbr,abbr);
    strcpy(citta.nome,nome);
    citta.abitanti=n;

    Lista *nodo=malloc(sizeof(Lista));

    nodo->citta=citta;
    nodo->next=*l;
    *l=nodo;
    puts("Nodo implementato");
    return 1;
}

int stampaSuFile(Lista *l){

    FILE *fp;
    char path[100];
    printf("Inserire il path seguito dal nome del file\n");
    scanf("%s", path);

    if (fp=fopen(path,"w"))
    {
        while (l!=NULL)
        {
            fprintf(fp,"%2s %19s %d",l->citta.abbr,l->citta.nome,&l->citta.abitanti);
            l=l->next;
        }
        fclose(fp);
    }else 
    {
        puts("Errore! Impossibile aprire il file desiderato");
        return 0;
    }
    return 1;
    
    
    
}

void stampaLista(Lista *l){

    if (l == NULL)
    {
        puts("Lista vuota");
    }
    while (l!=NULL)
    {
        printf("%s %s %d",l->citta.abbr,l->citta.nome,l->citta.abitanti);
        l=l->next;
    }
}

int contaNodi(Lista *l)
{

    int i = 0;
    while (l != NULL)
    {
        l = l->next;
        i++;
    }

    return i;
}

void infoAbitanti(Lista *lista,int* array,int b,int c){

    while (lista!=NULL)
    {
        if (lista->citta.abitanti<=b)
        {
            array[0]++;
        }if (lista->citta.abitanti>=c)
        {
            array[2]++;
        }else
        {
            array[1]++;
        }
        lista=lista->next;        
    }
}

Lista *ordinaPerAbitanti(Lista *lista,size_t n){

    Lista *lista_1;
    Lista *lista_2;

    for (size_t i = 0; i < n-1; i++)
    {
        lista_1=lista;
        lista_2=lista->next;

        for (size_t j = 0; i < n-i-1; j++)
        {
            if (lista_2->citta.abitanti>lista_1->citta.abitanti)
            {
                Citta citta=lista_1->citta;
                lista_1->citta=lista_2->citta;
                lista_2->citta=citta;           
            }
            lista_1=lista_1->next;
            lista_2=lista_2->next;
        }
    }
    return lista;
}

Lista *inMaiuscolo(Lista *lista){

    Lista *head=lista;
    int offset=0;
    while (lista!=NULL)
    {
        int i=0;
        while (lista->citta.nome[i]!="\0")
        {
            if (lista->citta.nome[i]>='a' && lista->citta.nome[i]<='z')
            {
                offset=lista->citta.nome[i]-'a';
                lista->citta.nome[i]='A'+offset;
            }
            i++;
        }
        lista=lista->next;
    }
    return head;
}

Lista *pulisciLista(Lista *lista){

    Lista *tmp;

    while (lista!=NULL)
    {
        tmp=lista;
        lista=lista->next;
        free(tmp);
    }
    return lista;
}