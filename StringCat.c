#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void addSpaceBeforAndAfter(char *, const char *);
void customConcat(char *, const char *);

int main()
{

    char a[10];
    char b[50] = "ciao";
    char s1[20] = " ";
    char s2[] = "come stai";
    strcat(s1, s2);
    printf("%s", s1);
    strcat(b, " ");
    char *d;
    addSpaceBeforAndAfter(d, s2);
    customConcat(b, s2);
    strcat(b, s1);
    printf("%nno_space", d);

    //add only 5 character(spaces included) to b from d
    strncat(b, d, 5);
    printf("%s", b);
    return 0;
}

void addSpaceBeforAndAfter(char *p, const char b[])
{
    size_t i = 0;
    /************************
     * spazio all'inizio
    /*************************/
    p[0] = ' ';
    for (; (p[i + 1] = b[i]) != '\0'; i++)
    {
        // blank
    }
    // printf("i = %d\n", i);
    /************************
     * spazio alla fine
     * il ++ è dovuto al fatto che l'indice i è stato usato con un costante +1 nel ciclo for precente
    /*************************/
    p[++i] = ' ';
}

void customConcat(char *p, const char b[])
{
    size_t i = 0;
    for (; (p[i]) != '\0'; i++)
    {
        // printf("i = %d\n",i);
        // printf("p[%d] = %c\n",i,p[i]);
        //  blank
    }
    // printf("i = %d\n",i);
    // printf("p[%d] = %c\n",i,p[i]);

    /************************
     * in questo caso l'indice i va bene così
    /*************************/
    p[i] = ' ';
    // printf("i = %d\n",i);
    // printf("p[%d] = %c\n",i,p[i]);
    for (size_t j = 0; (p[i + 1] = b[j]) != '\0'; j++, i++)
    {
        // blank
    }
}