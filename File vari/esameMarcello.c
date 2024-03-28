#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PATH "C:/Unipa/Programmazione/File.txt/salvataggio.txt"
#define SIMBOLO_1 'X'
#define SIMBOLO_2 'O'

size_t N = 5;


struct giocatore {
	char nome[10];
	char simbolo;
    /*Definire struttura*/
};
typedef struct giocatore Giocatore;

/*Funzioni opzionali*/
void stampa_griglia(size_t n, char griglia[][n]);
int conta_celle_vuote(size_t n, char griglia[][n]);
void mossa(Giocatore g, size_t n, char griglia[][n]);

/*Funzioni obbligatorie*/
int carica_partita(Giocatore* g1, Giocatore* g2, size_t N, char griglia[][N]);
int colonne_righe(Giocatore g, size_t n, char griglia[][n]);
int diag_secondaria(size_t n, char griglia[][n], Giocatore g);
int conta_segni(Giocatore g, size_t r, size_t c, size_t b, char griglia[][N]);


int main(){
	FILE*fp = NULL;
	Giocatore *g1 = malloc(sizeof(Giocatore));
	Giocatore *g2 = malloc(sizeof(Giocatore));
	int l;
	char griglia[N][N];
    carica_partita(g1, g2, N, griglia);
    printf("\n");
    stampa_griglia(N, griglia);
    int count = conta_celle_vuote(N, griglia);
    printf("il numero di celle vuote è %d\n", count);
    Giocatore _g;
    int vittoria = colonne_righe(_g, N, griglia);
    if(vittoria == 1){
    	printf("il vincitore è il giocatore da te scelto\n");
    }if(vittoria == 0){
    	printf("Pareggio\n");
    }
    diag_secondaria(N, griglia, _g);
    size_t r = N-1;
    size_t c = N;
    size_t b = 0;
    char simbolo1 = 'X';
    _g.simbolo = simbolo1;

    b = conta_segni( _g, r, c, b, griglia);
    printf("il numero di %c è %d\n", _g.simbolo, b);


    /*Definire il main*/
}



int carica_partita(Giocatore* g1, Giocatore* g2, size_t N, char griglia[][N]){
	FILE* fp = fopen(PATH,"r");
	char turno[10];
	char nometemp[10] = "peppino";
	char simbolotemp = 'X';
	int flag = 1;
	
    
    while(flag < 3){
    	fscanf(fp, "%s %c", nometemp,  &simbolotemp);

    	if(flag == 1){
    		memcpy(g1->nome, nometemp,9);
    		g1->simbolo = simbolotemp;
    		printf("Il giocatore 1 è:%-10sil suo simbolo è : %c\n", g1->nome, g1->simbolo);
   
    	}else{
    		memcpy(g2->nome, nometemp,9);
    		g2->simbolo = simbolotemp;
    		printf("Il giocatore 2 è:%-10sil suo simbolo è : %c\n", g2->nome, g2->simbolo);
    		
    	}
    	flag = flag + 1; 
    	
    }
    
    fscanf(fp, "%s", turno);
    printf("è il turno di %s\n", turno);
   
    printf("\n");
    for(size_t k = 0; k < N; k++){
    	for(size_t j = 0; j < N; j++)
    		fscanf(fp,"%s \n", &griglia[k][j]);  // passo la matrice del file all'array come array di stringhe
    	
    }
    stampa_griglia(N, griglia);
    return 0;

  
}

void stampa_griglia(size_t N, char griglia[][N]){
	for(size_t k = 0; k < N; k++){
    	for(size_t j = 0; j < N; j++){
    		printf("%c ", griglia[k][j]);

    	}
    	printf("\n");
    } 
    

    return;

}

int conta_celle_vuote(size_t n, char griglia[][n]){
	char vuoto = 'e';
	int count = 0;
	for(size_t k = 0; k < N; k++){
    	for(size_t j = 0; j < N; j++){
    		if(griglia[k][j] == vuoto){
    			count++;
    		}
    		

    	}
    } 
    

    return count;

}

int colonne_righe(Giocatore g, size_t n, char griglia[][n]){
	
    int contatore = 0;
    int scelta;
    printf("Inserire il nome del giocatore scelto(0 = Giuseppe(X)/1 = Luca(O))\n");
    scanf("%d",&scelta);
    Giocatore _g;
    if(scelta == 0){
       _g.simbolo = 'X';
    }else{
       _g.simbolo = 'O';
    }
    
    char simbolo1 = 'X';
    char simbolo2 = 'O';
    if(_g.simbolo == simbolo1){
       
       for(int j = 0; j < N; j++){
    	  for(int k = 0; k < N; k++){
    		if(griglia[k][j] == simbolo1){
    			contatore++;
    			//printf("%d\n", contatore );
    			
    			
    		    
    		}
    	}
    	if(contatore == 5){
    		printf("Ha ottenuto 5 simboli sulla colonna %d\n", j+1);
    		return 1;
    	}else{
    		contatore = 0;
    	}

      }
    }if(_g.simbolo == simbolo2){
       
       for(int j = 0; j < N; j++){
    	  for(int k = 0; k < N; k++){
    		if(griglia[k][j] == simbolo1){
    			contatore++;
    			//printf("%d\n", contatore );
    			
    			
    		    
    		}
    	}
    	if(contatore == 5){
    		printf("Ha ottenuto 5 simboli sulla colonna %d\n", j+1);
    		return 1;
    	}else{
    		contatore = 0;
    	}

      }

    }if(_g.simbolo == simbolo1){
       
       for(int k = 0; k < N; k++){
    	  for(int j = 0; j < N; j++){
    		if(griglia[k][j] == simbolo1){
    			contatore++;
    			//printf("%d\n", contatore );
    			
    			
    		    
    		}
    	}
    	if(contatore == 5){
    		printf("Ha ottenuto 5 simboli sulla riga %d\n", k+1);
    		return 1;
    	}else{
    		contatore = 0;
    	}

      }
    }if(_g.simbolo == simbolo2){
       
       for(int k = 0; k < N; k++){
    	  for(int j = 0; j < N; j++){
    		if(griglia[k][j] == simbolo2){
    			contatore++;
    			//printf("%d\n", contatore );
    			
    			
    		}
    	}
    	if(contatore == 5){
    		printf("Ha ottenuto 5 simboli sulla riga %d\n", k+1);
    		return 1;
    	}else{
    		contatore = 0;
    	}
      }
  }
  return 0;
}  

int diag_secondaria(size_t n, char griglia[][n], Giocatore g){
	int contatore = 0;
    int scelta;
    printf("Inserire il nome del giocatore scelto(0 = Giuseppe(X)/1 = Luca(O))\n");
    scanf("%d",&scelta);
    Giocatore _g;
    if(scelta == 0){
       _g.simbolo = 'X';
    }else{
       _g.simbolo = 'O';
    }
    
    char simbolo1 = 'X';
    char simbolo2 = 'O';
    int j = 0;

    if(_g.simbolo == simbolo1){ //conta le X
    	for(int k = N-1; k >= 0; k--){
    		if(j < N){
    		   
    		   if(griglia[k][j] == simbolo1){
    			contatore++;
    			
    			}  
    		}
    		j++;
    		
    	}
    	//printf("%d\n", contatore );
    }

    if(_g.simbolo == simbolo2){ //conta le O
    	for(int k = N-1; k >= 0; k--){
    		if(j < N){
    		   
    		   if(griglia[k][j] == simbolo2){
    			contatore++;
    			
    			}  
    		}
    		j++;
    		
    	}
    	//printf("%d\n", contatore );
    }
	printf("il numero sulla diagonale diag_secondaria è : %d\n", contatore);
    return 0;
}


int conta_segni(Giocatore g, size_t r, size_t c, size_t b, char griglia[][N]){
	
	//printf("%d\n", n );
    char simbolo1 = 'X';
    Giocatore _g;
    _g.simbolo = simbolo1; 
    if(r== 4 && c== 5){
       stampa_griglia(N, griglia);
    }
    c--;
    
    if(r == 0 && c == 0 && griglia[0][0] == _g.simbolo) {
    	//printf("%c\n", griglia[r][c]);
    	return b+1 ;
       }
    if(r == 0 && c == 0 && griglia[0][0] != _g.simbolo) return b ;
    if(r >= 0 && c >=0){
        
        //printf("%c\n", griglia[r][c] );
        if(griglia[r][c] == _g.simbolo){
    		b++;
    		//printf("il numero di righe %d e colonna%d\n", r, c);
    	
    	}
    	if(c == 0){
    		r--;
    		c = N;
        }
    	
    	return conta_segni( _g, r, c, b, griglia);    	
    }
    
}
    		

    	

    	
    	   


    		   
     


	