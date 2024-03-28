#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "C:/Unipa/Programmazione/File.txt/citta.txt"

struct citta {
  char abbr[3];
  char estesa[20];
  int abitanti;
};
typedef struct citta Citta;

struct lista {
	Citta citta;
	struct lista *next;
};
typedef struct lista Lista;


size_t numeroRighe(FILE*);
Lista* creaLista(FILE*);
void stampaLista(Lista*);
Lista* pulisciLista(Lista*);
int cercaInLista(Lista **l);
void infoAbitanti(Lista*, int*, int, int);
Lista* ordinaPerAbitanti(Lista*, size_t);
int contaElementi(Lista*);
int stampaSuFile(Lista*);
Lista* inMaiuscolo(Lista*);

int main(){
	FILE *fp = NULL;

	if ((fp = fopen(PATH, "r")) != NULL){

		size_t righe = numeroRighe(fp); 
		printf("Ci sono %zu righe nel file\n\n", righe);
		
		// Serve per posizionare il puntatore al file al primo carattere
		rewind(fp);

		Lista* l = creaLista(fp);
		stampaLista(l);
		fclose(fp);

		int resp = cercaInLista(&l);
		if (resp == 0){
			printf("Coppia trovata\n\n");
		} else if (resp == 1){
			printf("Coppia non trovata ed aggiunta alla lista\n\n");
		} else {
			printf("Trovata solo l'abbreviazione\n\n");
		}

		int n = contaElementi(l);
		printf("Ci sono %d nodi",n);

		int array[] = {0,0,0};
		int lower = 300000;
		int upper = 600000;
		infoAbitanti(l, array, lower, upper);
		printf("minore o uguale a lower: %d\ncompreso tra lower e upper: %d \nmaggiore o uguale ad upper: %d\n\n", 
				array[0], array[1], array[2]);

		printf("Lista ordinata per abitanti\n");
		
		l = ordinaPerAbitanti(l,n);
		stampaLista(l);

		l = inMaiuscolo(l); 
		stampaLista(l);

		stampaSuFile(l);

		l = pulisciLista(l);

	} else {
		printf("File inesistente o directory sbagliata\n");
	}
	
	return 0;
}

size_t numeroRighe(FILE *fp){
	size_t count = 0;
	char buf = fgetc(fp);
	if (buf == EOF) {
		return count;
	} else {
		while(buf != EOF){
			if (buf == '\n')
				count++;
			buf = fgetc(fp);
		}
	}
	return count+1;
}

Lista* creaLista(FILE* fp){
	Lista* head = NULL;
	Lista* tmp = NULL;
	Citta _citta;
	while (fscanf(fp, "%s %s %d", _citta.abbr, _citta.estesa, &_citta.abitanti) > 0){
		// Se la lista è vuota, inizializza la testa
		if (head == NULL){
			head =  malloc(sizeof(Lista));
			head->citta = _citta;
			head->next = NULL;
		}
		//...altrimenti appendi
		else{
			tmp =  malloc(sizeof(Lista));
			tmp->citta = _citta;
			tmp->next = head;
			head = tmp;			
		}
	}
	return head;
}

void stampaLista(Lista* l){
	while(l != NULL){
		printf("%s %s %d\n", l->citta.abbr, l->citta.estesa, l->citta.abitanti);
		l = l->next;
	}
	printf("\n\n");
	return;
}

Lista* pulisciLista(Lista* l){
	Lista *tmp;
	while(l != NULL){
		tmp = l->next;
		free(l);
		l = tmp;
	}
	return l;
}

int cercaInLista(Lista** l) {
	char _abbr[3];
	char _estesa[20];
	printf("Inserire abbreviazione: \n");
	scanf("%s", _abbr);
	printf("Inserire estesa: \n");
	scanf("%s", _estesa);

	/*Mantengo il puntatore alla testa della lista*/
	Lista *head = *l;

    while (head != NULL){
    	// Coppia trovata
        if (strcmp((head->citta).abbr,_abbr)==0 && strcmp((head->citta).estesa,_estesa)==0)
            return 0;
        // Trovata solo l'abbreviazione
        if (strcmp((head->citta).abbr,_abbr)==0 && strcmp((head->citta).estesa,_estesa)!=0)
            return 2;
        head = head->next;
    }

	// Se sono arrivato qui, devo appendere la nuova voce e ritornare 1
    printf("Voce non trovata.\n");
    printf("Inserire numero abitanti: \n");
    int _abitanti;
	scanf("%d", &_abitanti);
	Citta _citta;
    strcpy(_citta.abbr, _abbr);
    strcpy(_citta.estesa, _estesa);
    _citta.abitanti = _abitanti;
    
    Lista* nodo =  malloc(sizeof(Lista));
    nodo->citta = _citta;
    nodo->next = *l;
    *l = nodo;
    
    return 1;
}

void infoAbitanti(Lista* l, int* array, int a, int b){
    while (l != NULL){
        if (l->citta.abitanti <= a)
        	array[0]++;
        else if (l->citta.abitanti >= b)
        	array[2]++;
        else
        	array[1]++;
        l = l->next;
    }
    return;
}

Lista* ordinaPerAbitanti(Lista* l, size_t n){
	int i, j;
	Lista* tmp_j;
	Lista* tmp_j_1; 
	for (i = 0; i < n-1; i++){
		tmp_j = l;
		tmp_j_1 = l->next;
		for (j = 0; j < n-i-1; j++){
			if (tmp_j->citta.abitanti > tmp_j_1->citta.abitanti){
				Citta citta_tmp = tmp_j_1->citta;
				tmp_j_1->citta = tmp_j->citta;
				tmp_j->citta = citta_tmp;
			}
			tmp_j = tmp_j->next;
			tmp_j_1 = tmp_j_1->next;
		}
    }
    return l;
}


int contaElementi(Lista* l){
	int count = 0;
	while(l != NULL){
		count++;
		l = l->next;
	}
	return count;
}


int stampaSuFile(Lista* l){
	FILE* fp;
	char path[100];
	printf("Inserire il path seguito dal nome del file\n");
	scanf("%s", path);

	if((fp = fopen(path, "w")) != NULL){
		while(l != NULL){
			//printf("%s", l->citta.abbr);
			fprintf(fp, "%s %s %d\n", l->citta.abbr, l->citta.estesa, l->citta.abitanti);
			l = l->next;
		}
		fclose(fp);
	} else {
		printf("Errore nella scrittura del file\n");
		return 0;
	}
	return 1;
}

Lista* inMaiuscolo(Lista* l){
	Lista* head = l;
	int offset = 0;
	while(l != NULL){
		int i = 0;
		while(l->citta.estesa[i] != '\0'){
			if('a'<= l->citta.estesa[i] && l->citta.estesa[i] <= 'z'){
				offset = l->citta.estesa[i] - 'a';
				l->citta.estesa[i] = 'A' + offset;
			}
			++i;
		}
		l = l->next;
	}
	return head;
}