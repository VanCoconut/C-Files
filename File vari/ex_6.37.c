
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

int minimo(int a[], int n);

int main(void)
{

    int a[SIZE];
    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++)
    {

        a[i] = 1 + rand() % 1000;
    }
    printf("i valori estratti sono:\n");
    for (size_t i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nIl valore minore e': %d", minimo(a, SIZE));
}

int minimo(int a[], int n)
{

    if (n == 0)
    {
        return a[0];
    }
    else
    {
        //return ((a[n-1]<minimo(a,n-1))? a[n-1] : minimo(a,n-1)); //operatore ternario
        if (a[n - 1] < minimo(a, n - 1))
        {
            return a[n - 1];
        }
        else
        {
            return minimo(a, n - 1); //non si sa il perchè ma si può togliere questa linea di codice e funziona lo stesso
        }
    }
}

/*if  (a[n - 1] < minimo(a, n - 1))
{
  return a[n-1];
}else
{
  return minimo(a, n - 1);
}
*/
