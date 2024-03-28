#include <stdio.h>

int main(void){

    int counter;
    int num;
    int sum;

    printf("How many numbers do you wanto to do the sum?\n");

    scanf("%d",&counter);

    for ( int i = 0; i < counter; i++)
    {
        printf("Enter the number\n");
        
        scanf("%d",&num);

        sum=+num;
       
    }

    printf("The sum of all numbers is: %d\n", sum);
}