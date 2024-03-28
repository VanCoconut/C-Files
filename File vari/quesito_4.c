#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int num;
    struct Node *node;
}Node;


void display(Node *head);
void push(Node **top, int value);
int pop(Node **top);
int topOfStack(Node *top);
int isempty(Node *top);

int main(){

    Node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);
    printf("The top is %d\n", topOfStack(top));
    pop(&top);
    printf("The top after pop is %d\n", topOfStack(top));
    display(top);
    return 0;
}

void push(Node **top,int value){

    Node *newPtr=malloc(sizeof(Node));

    if (newPtr!=NULL){
        newPtr->num=value;
        newPtr->node=*top;
        *top=newPtr;
    }else
    {
        printf("Errore");
    }    
}

int pop(Node **top){
    Node *tmp=*top;
    int popvalue=(*top)->num;
    *top=(*top)->node;
    free(tmp);
    return popvalue;
}

int topOfStack(Node *top){
    int popvalue=top->num;
}

void display(Node *head){

    if (head == NULL)
    {
        printf("\0\n");
    }
    else
    {
        printf("%d\n", head->num);
        display(head->node);
    }
}

int isempty(Node *top){
    if (top == NULL)
    {
        puts("La lista e' vuota");  
        return 1;      
    }else
    {
        puts("La lista contiene elementi");
        return 0;
    }  
}