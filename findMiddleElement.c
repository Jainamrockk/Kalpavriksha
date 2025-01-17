#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{

    int data;
    struct listNode* next;
}listNode;
 listNode* head;
 listNode* tail;

void insertElement(int value)
{
    if(head == NULL)
    {
        head = (listNode*)malloc(sizeof(listNode));
        head->data = value;
        head->next = NULL;
        tail = head;
        return;
    }
    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->data = value;
    node->next = NULL;
    tail->next = node;
    tail = node;
}

void printMiddleElement()
{
    if(head == NULL)
    {
        printf("Empty Linked List");
        return;
    }
    if(head->next == NULL)
    {
        printf("%d ",head->data);
        return;
    }
    listNode* slow = head;
    listNode* fast = head->next;
    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL)
        fast = fast->next;
    }
    printf("Middle Element is : %d",slow->data);
}

int getInteger(char* input)
{
    int value = 0;
    while(*input!='\0')
    {
        if(*input>='0' && *input<='9')
        {
            value = value*10 + *input - '0';
        }
        else if(*input!='\n')
        {
            printf("Invalid Input\n");
            exit(0);
        }
        input++;
    }
    return value;
}

int main()
{
    int value;
    head = NULL;
    while(1)
    {
        char* input = (char*)malloc(sizeof(char));
        scanf("%s",input);
        value = getInteger(input);
        insertElement(value);
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
    printMiddleElement();
    return 0;
}