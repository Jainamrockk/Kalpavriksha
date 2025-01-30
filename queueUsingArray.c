#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int* arr;
    int front;
    int rear;
    int capacity;
}queue;

int isEmpty(queue* q)
{
    return (q->front == -1);
}

int isFull(queue* q)
{
    return (q->rear == q->capacity - 1);
}

void enqueue(queue* q)
{
    if(isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if(isEmpty(q))
    {
        q->front = 0;
    }
    int value;
    scanf("%d",&value);
    q->arr[++q->rear] = value; 
}

void dequeue(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
        return;
    }
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front++;
}


void peek(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n",q->arr[q->front]);
}

void size(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n",q->rear - q->front + 1);
}

int main()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    printf("Enter the size of queue: ");
    scanf("%d",&q->capacity);
    q->arr = (int*)malloc(sizeof(int)*q->capacity);

    while(1)
    {
        printf("Enter the Operation:\n1.Enqueue\n2.Dequeue\n3.peek\n4.isEmpty\n5.size\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                if(isEmpty(q))
                    printf("Queue is Empty\n");
                else
                    printf("Queue is not Empty\n");
                break;
            case 5:
                size(q);
                break;
            default:
                printf("Invalid Input\n");
                break;        
        }
    }

    return 0;
}