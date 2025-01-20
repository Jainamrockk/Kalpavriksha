#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{

    int data;
    struct listNode *next;
} listNode;

int totalNodes;
listNode *head;
listNode *tail;

void insertAtBeginning(int value)
{
    int flag = 0;

    if (head == NULL)
        flag = 1;
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = value;
    node->next = head;
    head = node;

    if (flag == 1)
    {
        tail = head;
        return;
    }
    totalNodes++;
}

void insertAtEnd(int value)
{
    if (head == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = value;
    node->next = NULL;
    tail->next = node;
    tail = node;
    totalNodes++;
}

void insertAtPosition(int pos, int value)
{

    if (pos == totalNodes + 1)
    {
        insertAtEnd(value);
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning(value);
        return;
    }

    if (pos > totalNodes || pos <= 0 || head == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    listNode *ptr = head;

    while (pos != 2)
    {
        ptr = ptr->next;
        pos--;
    }

    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->data = value;
    node->next = ptr->next;
    ptr->next = node;
    totalNodes++;
}

void display()
{
    if (head == NULL)
        return;
    listNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int value)
{
    if (position > totalNodes || position <= 0 || head == NULL)
        return;

    listNode *ptr = head;

    while (position != 1)
    {
        ptr = ptr->next;
        position--;
    }

    ptr->data = value;
}

void deleteAtBeginning()
{
    if (head == NULL)
        return;
    listNode *ptr = head;
    head = head->next;
    ptr->next = NULL;
    free(ptr);
    totalNodes--;
}

void deleteAtEnd()
{
    if (head == NULL || tail == NULL)
    {
        return;
    }
    listNode *ptr = head;
    while (ptr->next != tail)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(tail);
    tail = ptr;
    totalNodes--;
}

void deleteAtPosition(int position)
{
    if (head == NULL || position <= 0 || position > totalNodes)
    {
        printf("Invalid Position\n");
        return;
    }
    if (position == totalNodes)
    {
        deleteAtEnd();
        return;
    }
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }

    listNode *ptr = head;
    while (position != 2)
    {
        ptr = ptr->next;
        position--;
    }
    listNode *node = ptr->next;
    ptr->next = node->next;
    node->next = NULL;
    free(node);
    totalNodes--;
}

int main()
{
    int numberOfOperations;
    scanf("%d", &numberOfOperations);

    if (numberOfOperations <= 0)
    {
        return 0;
    }

    totalNodes = 1;
    head = NULL;
    while (numberOfOperations > 0)
    {
        int choice, value, pos;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 2:
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 3:
            scanf("%d%d", &pos, &value);
            insertAtPosition(pos, value);
            break;
        case 4:
            display();
            break;
        case 5:
            scanf("%d%d", &pos, &value);
            updateAtPosition(pos, value);
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        default:
            printf("Invalid\n");
            exit(0);
        }
        numberOfOperations--;
    }
    return 0;
}