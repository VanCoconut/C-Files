#include <stdio.h>

int main(void){

    int counter;
    int grade;
    int total;
    float averange;
    int num;

    num=1;
    total=0;
    counter=0;

    

    printf("Scrivi voto dell'esame n. %d, oppure inserisci \"-1\" per andare avanti\n",num);

    scanf("%d",&grade);

    while (grade!=-1)
    {
        total+=grade;

        num++;

        counter++;

        printf("Scrivi voto dell'esame n. %d, oppure inserisci \"-1\" per andare avanti\n", num);

        scanf("%d",&grade);
    }

    if (counter!=0)
    {
        averange=(float) total/counter;

        printf("The averange is : %f\n",averange);
    }

    else
    {
        printf("%s","Non sono stati inseriri voti, impossibile proseguire");
    }  
    
    return 0;
    
}