#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    char data;
    struct listNode *nextNode;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *p);
void delete(ListNodePtr *p);
int isEmpty(ListNodePtr p);
void printList(ListNodePtr p);
int instructions(void);

int main()
{

    ListNodePtr startPtr = NULL;
    char item;
    int choice = 0;

    while (choice != 3)
    {
        choice = instructions();
        switch (choice)
        {
        case 1:
            insert(&startPtr);
            printList(startPtr);
            break;
        case 2:
            if (!isEmpty(startPtr))
            {
                delete (&startPtr);
                printList(startPtr);
            }
            else
            {
                puts("List is empty");
            }
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }
    return 0;
}

void insert(ListNodePtr *p)
{
    char c;
    puts("Enter a character: ");
    scanf("%c", &c);

    ListNodePtr newPtr = malloc(sizeof(ListNode));
    if (newPtr != NULL)
    {
        newPtr->data = c;
        newPtr->nextNode = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *p;

        while (currentPtr != NULL && c > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextNode;
        }

        if (previousPtr == NULL)
        {
            newPtr->nextNode = *p;
            *p = newPtr;
        }
        else
        {
            previousPtr->nextNode = newPtr;
            newPtr->nextNode = currentPtr;
        }
    }
    else
    {
        puts("No memory available");
    }
}
void delete(ListNodePtr *p)
{
    char c;
    puts("Enter a character: ");
    scanf("%c", &c);

    if (c==(*p)->data)
    {
        ListNodePtr tempPtr=*p;
        *p=(*p)->nextNode;
        free(tempPtr);
    }else
    {
         ListNodePtr previousPtr = *p;
        ListNodePtr currentPtr = (*p)->nextNode;

        while (currentPtr != NULL && currentPtr->data != c)
        {
            previousPtr=currentPtr;
            currentPtr=currentPtr->nextNode;
        }
        if (currentPtr!=NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextNode=currentPtr->nextNode;
            free(tempPtr);
        }
        
        
    }
    
    
}
int isEmpty(ListNodePtr p)
{
    return p == NULL;
}
void printList(ListNodePtr currentPtr)
{
    if (isEmpty(currentPtr))
    {
        puts("List is empty");
    }
    else
    {
        puts("The list is: ");

        while (!isEmpty(currentPtr))
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextNode;
        }
        puts("NULL");
    }
}
int instructions(void)
{
    int choice = 0;
    puts("Select a choice: \n"
         "1 - to insert an element into the list\n"
         "2 - to delete an elemento from the list\n"
         "3 - to quit\n");
    scanf("%c");
    scanf("%d", &choice);
    return choice;
}