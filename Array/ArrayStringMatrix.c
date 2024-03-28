#include <stdio.h>

#define ROWS 3
#define COLS 3
#define STRING_LENGTH 10

int main()
{

    const char *matrix[ROWS][COLS] = {
        {"aa", "bb", "cc"},
        {"dd", "ee", "ff"},
        {"gg", "hh", "ii"},
    };
    char string_matrix[ROWS][COLS][STRING_LENGTH] = {
        {"aa", "bb", "cc"},
        {"dd", "ee", "ff"},
        {"gg", "hh", "ii"},
    };

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("matrix[%d][%d] is %s\n", i, j, matrix[i][j]);
        }
    }

    // OR

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("matrix[%d][%d] is %s\n", i, j, string_matrix[i][j]);
        }
    }

    return 0;
}