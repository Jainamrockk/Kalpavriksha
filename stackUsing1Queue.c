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
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front++;
        
    return value;
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

int size(queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack is Empty\n");
        return 0;
    }
    return q->rear - q->front + 1;
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
        // printf("Stack Overflow\n");
       (st->mainQueue)->capacity *= 2;
       (st->mainQueue)->arr = (int*)realloc((st->mainQueue)->arr,sizeof(int)*(st->mainQueue)->capacity);
    }
    int value;
    scanf("%d", &value);
    enqueue(st->mainQueue, value);
    if (isEmpty(st->mainQueue))
    {
        return;
    }

    int qSize = size(st->mainQueue);

    for (int i = 0; i < qSize - 1; i++)
    {
        int frontVal = dequeue(st->mainQueue);
        enqueue(st->mainQueue, frontVal);
    }
    printf("Front: %d  Rear: %d \n", (st->mainQueue)->front, (st->mainQueue)->rear);
}

int main()
{

    int capacity;
    printf("Enter the capacity of Stack: ");
    scanf("%d", &capacity);
    stack *st = (stack *)malloc(sizeof(stack));
    st->mainQueue = initializeStackQueue(st->mainQueue, capacity);
    while (1)
    {
        printf("Enter the Operation:\n1.Push\n2.Pop\n3.peek\n4.isEmpty\n5.size\n");
        int choice, qSize;
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
            qSize = size(st->mainQueue);
            if (qSize != 0)
            {
                printf("Size: %d\n", qSize);
            }
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }

    return 0;
}