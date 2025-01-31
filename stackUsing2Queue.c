#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
} queue;

typedef struct stack
{
    queue *mainQueue;
    queue *helper;
    int capacity;
} stack;

int isEmpty(queue *q)
{
    return (q->front == -1);
}

int isFull(queue *q)
{
    return (q->rear == q->capacity - 1);
}

void enqueue(queue *q, int value)
{
    if (isFull(q))
    {
        printf("Stack is Full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack Underflow\n");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front++;
}

void peek(queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("%d\n", q->arr[q->front]);
}

void size(queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("%d\n", q->rear - q->front + 1);
}

queue *initializeStackQueue(queue *q, int capacity)
{
    q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    return q;
}

void push(stack *st)
{
    if (isFull(st->mainQueue))
    {
        printf("Stack Overflow\n");
        return;
    }
    int value;
    scanf("%d", &value);
    if (isEmpty(st->mainQueue))
    {
        enqueue(st->mainQueue, value);
        return;
    }

    st->helper = initializeStackQueue(st->helper, st->capacity);
    printf("%d\n",(st->helper)->capacity);
    int index = 0;
    while (!isEmpty(st->mainQueue))
    {

        enqueue(st->helper, (st->mainQueue)->arr[(st->mainQueue)->front]);
        dequeue(st->mainQueue);
    }

    enqueue(st->mainQueue, value);
    index = 0;
  
    while (!isEmpty(st->helper))
    {
        int val1 = (st->helper)->arr[(st->helper)->front];

        enqueue(st->mainQueue, val1);
        dequeue(st->helper);
    }
    free(st->helper);
}

int main()
{

    int capacity;
    printf("Enter the capacity of Stack: ");
    scanf("%d", &capacity);
    stack *st = (stack *)malloc(sizeof(stack));
    st->mainQueue = initializeStackQueue(st->mainQueue, capacity);
    st->capacity = capacity;
    while (1)
    {
        printf("Enter the Operation:\n1.Push\n2.Pop\n3.peek\n4.isEmpty\n5.size\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(st);
            break;
        case 2:
            dequeue(st->mainQueue);
            break;
        case 3:
            peek(st->mainQueue);
            break;
        case 4:
            if (isEmpty(st->mainQueue))
                printf("Stack is Empty\n");
            else
                printf("Stack is not Empty\n");
            break;
        case 5:
            size(st->mainQueue);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }

    return 0;
}