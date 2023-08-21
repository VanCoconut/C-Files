#include <stdio.h>

void sommaUno(int *);
void sommaDue(int *);
void sommaTre(int *);

int main()
{

    // array of pointers to functions
    void (*f[3])(int *) = {sommaUno, sommaDue, sommaTre};
    int choice = 0;
    int n = 0;
    printf("You have the zero number. Do you want to add 1,2 or 3. Type the adding number\n");
    scanf("%d", &choice);
    printf("You selected : %d\n", n);

    // instead of using any costruct like switch or if/else
    (*f[choice - 1])(&n);

    printf("You got : %d", n);

    return 0;
}

void sommaUno(int *a)
{
    ++*a;
}
void sommaDue(int *a)
{
    *a += 2;
}
void sommaTre(int *a)
{
    *a += 3;
}