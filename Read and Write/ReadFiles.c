#include <stdio.h>

int main()
{
    // WRITE/APPEND A FILE "w" to overwrite and "a" append use only absolutre path
    FILE *pF = fopen("C:\\Users\\Vincenzo Catalano\\Git\\C-Files\\test.txt", "r");

    char buffer[255];
    char nome[10];
    char segno;
    char nome2[10];
    char segno2;

    if (pF == NULL)
    {
        printf("no such file");
    }
    else
    {
        /*
            usando fscanf si può decidere lettera per lettera cosa prendere, in questo caso
            avendo un file da scansionare tipo
                LUCA X
                GIANNI O
            la prima parte della prima riga viene immagazzinata in nome (entro 100 caratteri),
            usaimo lo spazio per ignoare lo spazio presente nella prima riga e salviamo la  X
            nel segno, dopo di ciò lo scanner capisce di proseguire nell aseconda riga e si ripete l'iter
        */
        fscanf(pF, "%100s %c ", nome, &segno);
        printf("%s %c\n", nome, segno);
        fscanf(pF, "%100s %c", nome, &segno);
        printf("%s %c\n", nome, segno);

        // voelndo si può fare tutto in un unico fscanf
        // fscanf(pF, "%100s %c(lo spazio è indifferente va a capo lo stesso) %100s %c", nome, &segno,nome2, &segno2);

        // se vuoi stampare l'intero file
        while (fgets(buffer, 255, pF) != NULL)
        {
            //printf("%s", buffer);
        }

        /*
            se vuoi leggere a partire da uno specifico punto del file,
            per andare alle righe successive si deve paritire dal n+1 dove n è il
            numero di caratteri contenuti nella prima riga
        */
        puts("");
        puts("");
        fseek(pF, 1, SEEK_SET); // set file pointer to 2nd position (0-indexed)
        char part[10] = {0};    // array for 9 characters plus terminating 0
        fread(part, 1, 9, pF);  // read 9 members of size 1 (characters) from f into part
        puts(part);             // or any other way to output part, like using in printf()
    }

    fclose(pF);

    return 0;
}