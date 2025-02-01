#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr;
    int top;
    int size;
    int capacity;
} stack;

typedef struct queue
{

    stack *mainStack;
    stack *helper;

} queue;

int isEmpty(stack *st)
{
    if (st->top == -1)
        return 1;

    return 0;
}

stack *push(stack *st, int value)
{
    if (st->top == st->capacity)
    {
            printf("Memory Overload\n");
            exit(0);
    }

    st->arr[st->top + 1] = value;
    st->top++;
    return st;
}

void pop(stack *st)
{
    if (isEmpty(st) == 1)
    {
        printf("Queue Underflow\n");
        return;
    }
    st->top--;
}

void peek(stack *st)
{
    if (st->top == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n", st->arr[st->top]);
}

void size(stack *st)
{
    printf("Size of Queue is : %d\n", st->top + 1);
}

stack *initializeStack(stack *st, int capacity)
{
    st = (stack *)malloc(sizeof(stack));
    st->top = -1;
    st->size = 0;
    st->capacity = capacity;
    st->arr = (int *)malloc(capacity * sizeof(int));
    return st;
}

void enqueue(queue *q)
{
    int value;
    scanf("%d",&value);
    if(isEmpty(q->mainStack))
    {
        push(q->mainStack,value);
        return;
    }

    q->helper = initializeStack(q->helper,(q->mainStack)->capacity);

    while(!isEmpty(q->mainStack))
    {
        push(q->helper,(q->mainStack)->arr[(q->mainStack)->top]);
        pop(q->mainStack);
    }
    push(q->mainStack,value);
    while(!isEmpty(q->helper))
    {
        push(q->mainStack,(q->helper)->arr[(q->helper)->top]);
        pop(q->helper);
    }
    free(q->helper);
}

int main()
{
    int capacity;
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);
    queue *q = (queue *)malloc(sizeof(queue));
    q->mainStack = initializeStack(q->mainStack, capacity);

    while (1)
    {
        int choice;
        printf("\nEnter the operation.\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.Size\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(q);
            break;
        case 2:
            pop(q->mainStack);
            break;
        case 3:
            peek(q->mainStack);
            break;
        case 4:
            if (isEmpty(q->mainStack) == 1)
                printf("Stack is Empty\n");
            else
                printf("Stack is Not Empty\n");
            break;
        case 5:
            size(q->mainStack);
            break;
        default:
            printf("Enter Valid Input\n");
        }
    }
    return 0;
}