#include <stdio.h>
#include <ctype.h>

int main(){

    char unit;
    float temp;

    printf("\nDo you have C or F measuremnt? ");

    scanf("%c",&unit);

    unit = toupper(unit);

    if (unit == 'C')
    {
        printf("\nEnter the Celius temperature to convert\t");
        scanf("%f",&temp);
        temp = (temp*9/5)+32;
        printf("\nThere are %.1f F degrees",temp);
    }
    else if (unit == 'F')
    {
      printf("\nEnter the Farenheit temperature to convert\t");
        scanf("%f",&temp);
        temp = (temp-32)*5/9;
        printf("\nThere are %.1f C degrees",temp);
    }
    else
    {
        printf("\nError");
    }
    return 0;
}
