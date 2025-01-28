#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode *next;
    struct listNode *bottom;
} listNode;

listNode *createColumns()
{
    listNode *head = NULL;
    listNode *tail = NULL;
    while (1)
    {
        int value;
        scanf("%d", &value);
        if (head == NULL)
        {
            head = (listNode *)malloc(sizeof(listNode));
            head->val = value;
            head->next = NULL;
            tail = head;
        }
        else
        {
            listNode *node = (listNode *)malloc(sizeof(listNode));
            node->val = value;
            node->next = NULL;
            tail->next = node;
            tail = node;
        }
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }

    return head;
}

listNode *createLinkedList(listNode *col)
{
    listNode *head = NULL;
    listNode *tail = NULL;

    while (col)
    {
        listNode *node = NULL;
        listNode *nodeTail = NULL;
        int count = col->val;
        while (count>0)
        {
            int value;  
            scanf("%d", &value);
            count--;
            if (node == NULL)
            {
                node = (listNode *)malloc(sizeof(listNode));
                node->val = value;
                node->next = NULL;
                node->bottom = NULL;
                nodeTail = node;
                continue;
            }
            listNode *colNode = (listNode *)malloc(sizeof(listNode));
            colNode->val = value;
            colNode->next = NULL;
            colNode->bottom = NULL;
            nodeTail->bottom = colNode;
            nodeTail = colNode;
        }
        col = col->next;
        if (head == NULL)
        {
            head = node;
            tail = node;
            continue;
        }
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;

    return head;
}

void printLinkedList(listNode *head)
{
    while (head)
    {
        listNode *temp = head;
        while (temp)
        {
            printf("%d ", temp->val);
            if (temp->bottom != NULL)
            {
                printf("->");
            }
            temp = temp->bottom;
        }
        if (head->next != NULL)
        {
            printf("\n|\n");
        }
        head = head->next;
    }
    printf("\n\n");
}

void printLL(listNode *head)
{
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n\n");
}

listNode *merge(listNode *left, listNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->val <= right->val)
    {
        left->bottom = merge(left->bottom, right);
        return left;
    }
    right->bottom = merge(left, right->bottom);
    return right;
}

listNode *findMid(listNode *head)
{
    if(!head && !head->bottom)
    return head; 

    listNode *slow = head;
    listNode *fast = head->bottom;

    while (fast!=NULL && fast->bottom!=NULL)
    {
        slow = slow->bottom;
        fast = fast->bottom->bottom;
    }
    listNode *temp = slow->bottom;
    slow->bottom = NULL;
    return temp;
}

listNode *mergeSort(listNode *head)
{
    if (!head || !head->bottom)
        return head;

    listNode *mid = findMid(head);
    head = mergeSort(head);
    mid = mergeSort(mid);
    head = merge(head, mid);
    return head;
}

listNode *flatten(listNode *head)
{
    if (!head || !head->next)
        return head;

    head->next = flatten(head->next);
    head = merge(head, head->next);
    head->next = NULL;
    return head;
}

int findLength(listNode* head)
{
    int length = 0;
    while(head)
    {
        head = head->bottom;
        length++;
    }
    return length;
}


void findKthLargestElement(listNode* head,int findElement)
{
    while(findElement>0)
    {
        head = head->bottom;
        findElement--;
    }
    printf("%d",head->val);
}

int main()
{
    listNode *col = createColumns();
    listNode *head = createLinkedList(col);
    head = flatten(head);
    head = mergeSort(head);
    int listLength = findLength(head);
    int kthElement;
    scanf("%d",&kthElement);
    int findElement = listLength - kthElement;
    if(findElement<=0)
    {
        printf("Invalid\n");
        return 0;
    }
    findKthLargestElement(head,findElement);
    return 0;
}