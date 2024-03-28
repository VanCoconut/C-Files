#include <stdio.h>

int main()
{

    /*
        When you declare a 2d arrays aka a matrix you have to specified
        the number of rows and clomumns that will have,
        the compile do not control if you are trying to reach an out of bound index as you can see at
    */
    int matrix[3][3];

/*rows for 1d arrays*/
int array[2];
int r = sizeof(array)/sizeof(array[0]);

/*rows and columns for 2d array*/
    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    // printf("%d\t\n", rows);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            matrix[i][j] = j;
        }
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        puts("");
    }

    /*
        the last row is the 3th it should be initialized to
        default int array 0, however it does not work as expeted,
        return a not zero number 3
    */
    printf("%d\n", matrix[4][2]);
    /*
        instead this works as expected, its values is 0 
    */
    printf("%d\n", matrix[5][2]);

    return 0;
}