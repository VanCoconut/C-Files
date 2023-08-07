#include <stdio.h>

void happyBirthday(char name[], int age)
{
    printf("Happy Birthday %s. You turn %d years old", name, age);
}

int main()
{
    char name[] = "John";
    int age = 22;
    happyBirthday(name, age);
}