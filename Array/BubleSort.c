#include <stdio.h>

void sortInt(int array[], int size);
void sortChar(char array[], int size);
void displayIntArray(int array[], int size);
void displayCharArray(char array[], int size);

int main()
{
    int numbers[] = {2, 5, 3, 9, 6, 4, 1};
    char letter[] = {'C', 'E', 'B', 'A'};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // INT
    displayIntArray(numbers, size);
    sortInt(numbers, size);
    puts("");
    displayIntArray(numbers, size);

    puts("");

    // CHAR
    displayCharArray(letter, size);
    sortChar(letter, size);
    puts("");
    displayCharArray(letter, size);

    return 0;
}

void sortInt(int array[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
/* vai a capire perchè funziona e nel funzionare ordine in senso opposto al segno
void sort(int array[], int size)
{
    for (size_t i = 0; i < size ; i++)
    {
        for (size_t j = 0; j < size ; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i ] = temp;
            }
        }
    }
}*/

void sortChar(char array[], int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void displayIntArray(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}

void displayCharArray(char array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%c\t", array[i]);
    }
}