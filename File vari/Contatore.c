#include <stdio.h>

int main(void) {

    int contatore=0;
    int voto;
    int totale=0;
    float media;
    int num=1;

    printf("Scrivi voto dell'esame n. %d, oppure inserisci \"-1\" per andare avanti\n", num);

    scanf("%d", &voto);

    while (voto!=-1){

        totale=totale + voto;

        contatore++;

        num++;

        printf("Scrivi voto dell'esame n. %d, oppure inserisci \"-1\" per andare avanti\n", num);

        scanf("%d", &voto);        
  
    }

    if (contatore!=0)
        {
        media=(int) totale/contatore;
        printf("La tua media e': %.2f\n",media);
    }
    else
    {
        printf("Non sono stati inseriri voti, impossibile proseguire");
    } 

    
    
    return 0;

    
}