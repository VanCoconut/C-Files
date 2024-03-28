#include <stdio.h>
#include <string.h>
int main()
{

    char cars[][10] = {"Mustung", "Corvette", "Camaro"};

    /*rows string arrays used in iteration*/
    int rows = sizeof(cars) / sizeof(cars[0]);

    //replace a string inside the array
    strcpy(cars[0],"Tesla");

    for (size_t i = 0; i < rows; i++)
    {
        // if use \t it formats with no sense
        printf("%s\n", cars[i]);
    }

    return 0;
}