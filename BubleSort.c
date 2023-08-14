#include <stdio.h>

void sort(int array[], int size);
void displayIntArray(int array[], int size);

int main()
{
    int array[] = {2, 5, 3, 9, 6, 4, 1};
    int size = sizeof(array) / sizeof(array[0]);
    displayIntArray(array, size);
    printf("-----------------------------\n");
    sort(array, size);
    displayIntArray(array, size);

    return 0;
}

void sort(int array[], int size)
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

void displayIntArray(int array[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}