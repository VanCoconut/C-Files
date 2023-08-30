#include <stdio.h>
#include <string.h>


int main(){

    char griglia[5][5];

    /*for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                puts("");
            }
            griglia[i][j]=i+j;
            printf("%d\t",griglia[i][j]);            
        }
    }*/

    FILE *fp = fopen("C:/Unipa/Programmazione/File.txt/salvataggio2.txt", "r");

    
        for (size_t k = 0; k < 5; k++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                fscanf(fp, "%s \n", &griglia[k][j]);
                printf("%c ", griglia[k][j]);
            }
            puts("");
        }
}