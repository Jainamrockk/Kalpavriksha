#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int unique_id;
    char *severity;
    struct listNode *next;

} listNode;

listNode *head;
listNode *tail;

listNode* createList(int numberOfPatients)
{
    listNode* head = NULL;
    listNode* tail = NULL;
    while (numberOfPatients!=0)
    {
        int id;
        char *name = (char *)malloc(sizeof(char)*100);
        scanf("%d", &id);
        scanf("%s", name);
        numberOfPatients--;
        listNode *node = (listNode *)malloc(sizeof(listNode));
        node->unique_id = id;
        node->severity = name;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            tail = node;
            continue;
        }
        tail->next = node;
        tail = tail->next;
    }
    return head;
}

int stringCmp(char *string1, char *string2)
{
    while (*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 != *string2)
            return (*string1 - *string2);
        string1++;
        string2++;
    }
    return (*string1 - *string2);
}

listNode* sortList(listNode* head)
{
    listNode *critical = NULL;
    listNode *serious = NULL;
    listNode *stable = NULL;
    listNode *temp = head;
    listNode *temp1 = NULL;
    listNode *temp2 = NULL;
    listNode *temp3 = NULL;
    char* a = "Critical";
    char* b = "Serious";
    char* c = "Stable";
    while (temp)
    {
        if (stringCmp(temp->severity,a) == 0)
        {
            if (critical == NULL)
            {
                critical = temp;
                temp1 = temp;
            }
            else{
            temp1->next = temp;
            temp1 = temp;
        }
        }
        else if (stringCmp(temp->severity, b) == 0)
        {
            if (serious == NULL)
            {
                serious = temp;
                temp2 = temp;
            }
            else{
            temp2->next = temp;
            temp2 = temp;
        }
        }
        else if (stringCmp(temp->severity, c) == 0)
        {
            if (stable == NULL)
            {
                stable = temp;
                temp3 = temp;
            }
            else{
            temp3->next = temp;
            temp3 = temp;
        }
        }
        temp = temp->next;
    }
    if(temp1!=NULL)
    temp1->next = NULL;
    if(temp2!=NULL)
    temp2->next = NULL;
    if(temp2!=NULL)
    temp2->next = NULL;
    if(critical !=NULL)
    {
        head = critical;
        if(serious != NULL)
            temp1->next = serious;
            temp1 = temp2;
            temp1->next = stable; 
    }
    else if(serious!=NULL)
    {
        head = serious;
        if(stable!=NULL)
        {
            temp2->next = stable;
        }
    }
    else if(stable!=NULL)
    {
        head = stable;
    }
    else
    head = NULL;
    return head;
}

void printList(listNode* temp)
{
    while(temp!=NULL)
    {
        printf("%d %s ",temp->unique_id,temp->severity);
        temp = temp->next;
    }
}

int main()
{
    int numberOfPatients;
    scanf("%d", &numberOfPatients);
    head = NULL;

    head = createList(numberOfPatients);
    head = sortList(head);
    printList(head);
    return 0;
}