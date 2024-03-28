#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void copy(char *, const char *);
void copy2(char *const, const char *const);
void maiusc(char *);

int main()
{
    char a[10];
    char b[50] = "ciao";
    printf("%s", b);
    copy2(a, b);
    printf("a = %s\n", a);
    maiusc(a);
    printf("a = %s\n", a);
    return 0;
}

// using pointer annotation
void copy(char *a, const char *b)
{
    for (; (*a = *b) != '\0'; a++, b++)
    {
        // blank
    }
}

// using array annotation
void copy2(char *const a, const char *const b)
{
    for (size_t i = 0; (a[i] = b[i]) != '\0'; i++)
    {
        // blank
    }
}

void maiusc(char *p)
{
    for (; *p != '\0'; p++)
    {
        *p = toupper(*p);
    }
}
