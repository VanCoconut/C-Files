#include <stdio.h>

int main()
{
    // WRITE/APPEND A FILE "w" to overwrite and "a" append use only absolutre path
    FILE *pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\test.txt", "r");

    char buffer[255];

    if (pF == NULL)
    {
        printf("no such file");
    }
    else
    {
        while (fgets(buffer, 255, pF) != NULL)
        {
            printf("%s", buffer);
        }
    }
    fclose(pF);

    return 0;
}