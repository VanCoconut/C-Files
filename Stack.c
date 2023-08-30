#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    char data;
    struct stackNode *nextNode;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *p);
int pop(StackNodePtr *p);
int isEmpty(StackNodePtr p);
void printStack(StackNodePtr p);
int instructions(void);

int main()
{
    StackNodePtr stackPtr = NULL;
    char item;
    int choice = 0;

    while (choice != 3)
    {
        choice = instructions();
        switch (choice)
        {
        case 1:
            push(&stackPtr);
            printStack(stackPtr);
            break;
        case 2:
            if (!isEmpty(stackPtr))
            {
                printf("The popped valued is %d.\n", pop(&stackPtr));
                printStack(stackPtr);
            }
            else
            {
                puts("Stack is empty");
            }
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}

void push(StackNodePtr *p)
{

    StackNodePtr newPtr = malloc(sizeof(StackNode));

    int value = 0;
    printf("Enter a value to push: ");
    scanf("%d", &value);
    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextNode = *p;
        *p = newPtr;
    }
    else
    {
        puts("No memory");
    }
}
int pop(StackNodePtr *p)
{

    StackNodePtr tempPtr = p;
    int popValue = (*p)->data;
    *p = (*p)->nextNode;
    free(tempPtr);
    return popValue;
}
int isEmpty(StackNodePtr p)
{
    return p == NULL;
}
void printStack(StackNodePtr currentP)
{
    if (currentP == NULL)
    {
        puts("Stack is empty");
    }
    else
    {
        puts("The Stack is:");
        while (currentP != NULL)
        {
            printf("%d --> ,", currentP->data);
            currentP = currentP->nextNode;
        }
        puts("NULL");
    }
}
int instructions(void)
{
    int choice = 0;
    puts("Select a choice: \n"
         "1 - to push a value on the stack\n"
         "2 - to pop a value off the stack\n"
         "3 - to quit\n");
    scanf("%c");
    scanf("%d", &choice);
    return choice;
}