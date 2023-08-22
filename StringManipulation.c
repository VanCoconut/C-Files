#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char a[] = "ciao come stai";
    char b[] = "lumone";
    char *c = strchr(a, 'a');
    // c is a pointer to a, if found, and store the remaing part of the string
    printf("%s\n", c);

    // similar function but this time the second argument is a string
    char *d = strpbrk(a, b);
    printf("%s\n", d);

    // split the string "a" into tokens whenever it encounter a space (" ") or whatever you want
    char *token = strtok(a, " ");
    while (token != NULL)
    {
        printf("%s\t", token);
        // use NULL because you want to continue from the previous token
        token = strtok(NULL, " ");
    }

    return 0;
}