#include <stdio.h>
#include <math.h>
int main()
{

    char operation;
    float num1, num2, result;

    printf("Enter an operation: ");

    scanf("%f %c %f", &num1, &operation, &num2);

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        printf("%.2f %c %.2f = %.2f", num1, operation, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%.2f %c %.2f = %.2f", num1, operation, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%.2f %c %.2f = %.2f", num1, operation, num2, result);
        break;
    case '/':
        result = num1 / num2;
        printf("%.2f %c %.2f = %.2f", num1, operation, num2, result);
        break;
    default:
        printf("NO VALID OPERATION");
        break;
    }
}