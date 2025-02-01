#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode* next;
}listNode;

typedef struct stack
{
    listNode* top;
    int size;
}stack;

stack* push(stack* st)
{
    listNode* node = (listNode*)malloc(sizeof(listNode));
    if(node == NULL)
    {
        printf("Memory Overload\n");
        return st;
    }
    node->next = NULL;
    int value;
    scanf("%d",&value);
    node->val = value;
    if(st->top != NULL)
    {
        node->next = st->top;
    }
    st->size++;
    st->top = node;
    return st;
}


stack* pop(stack* st)
{
    if(st->top == NULL)
    {
        printf("Stack Underflow");
        return st;
    }
    listNode*  temp = st->top;
    st->top = (st->top)->next;
    st->size--;
    temp->next = NULL;
    free(temp);
    return st;
}

int isEmpty(stack* st)
{
    return (st->top == NULL);
}

void peek(stack* st)
{
    if(isEmpty(st))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top of Stack is:%d\n",(st->top)->val);
}

void size(stack* st)
{
    printf("%d\n",st->size);
}

int main()
{
    stack* st = (stack*)malloc(sizeof(stack));
    st->top = NULL;
    st->size = 0;
    while(1)
    {
        printf("\nEnter the operation:\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.Size\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                st = push(st);
                break;
            case 2:
                st = pop(st);
                break;
            case 3:
                peek(st);
                break;
            case 4:
                if(isEmpty(st))
                {
                    printf("Stack is Empty\n");
                }
                else
                printf("Stack is Not Empty");
                break;
            case 5:
                size(st);
                break;    
            default:
                printf("Enter a valid Input");
                break;
        }
    }
    return 0;
}