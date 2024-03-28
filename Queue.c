#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    char data;
    struct listNode *nextNode;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
