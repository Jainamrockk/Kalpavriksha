#include <stdio.h>
#include <stdlib.h>

typedef enum severity
{
    Stable,
    Serious,
    Critical
} severity;

typedef struct listNode
{
    int unique_id;
    severity severity;
    struct listNode *next;

} listNode;

char** severityName;

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

int checkUniqueId(int id,listNode* temp)
{
    listNode* head = temp;
    if(head == NULL)
    return 1;
    while(head)
    {
        if(id == head->unique_id)
        return 0;
        head = head->next;
    }
    return 1;
}

listNode *createList(int numberOfPatients)
{
    listNode *head = NULL;
    listNode *tail = NULL;
    while (numberOfPatients!=0)
    {
        int id;
        char *name = (char *)malloc(sizeof(char) * 100);
        scanf("%d", &id);
        scanf("%s", name);
         if(checkUniqueId(id,head) == 0)
        {
            printf("User Already Exists\n");
            continue;
        }
        listNode *node = (listNode *)malloc(sizeof(listNode));
        node->unique_id = id;
        if (stringCmp(name, "Critical") == 0)
        {
            node->severity = Critical;
        }
        else if (stringCmp(name, "Serious") == 0)
        {
            node->severity = Serious;
        }
        else if (stringCmp(name, "Stable") == 0)
        {
            node->severity = Stable;
        }
        else
        {
            printf("Enter Valid Severity\n");
            continue;
        }
        numberOfPatients--;
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


void printList(listNode *temp)
{
    if (temp == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d %s ", temp->unique_id,severityName[temp->severity]);
        temp = temp->next;
    }
}

listNode *findMid(listNode *head)
{
    if (!head || !head->next)
        return head;
    listNode *slow = head;
    listNode *fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        if(fast)
        slow = slow->next;
    }
    listNode *temp = slow->next;
    slow->next = NULL;
    return temp;
}

listNode *merge(listNode *left, listNode *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->severity>=right->severity)
    {
        left->next = merge(left->next, right);
        return left;
    }
    right->next = merge(left,right->next);
    return right;
}

listNode *mergeSort(listNode *head)
{
    if (!head || !head->next)
        return head;
    listNode *mid = findMid(head);
    head = mergeSort(head);
    mid = mergeSort(mid);
    head = merge(head, mid);
    return head;
}

void initializeSeverity()
{
    severityName = (char**)malloc(sizeof(char*)*3);
    severityName[0] = (char*)malloc(sizeof(char*)*10);
    severityName[1] = (char*)malloc(sizeof(char*)*10);
    severityName[2] = (char*)malloc(sizeof(char*)*10);
    severityName[2] = "Critical";
    severityName[1] = "Serious";
    severityName[0] = "Stable";
}

int main()
{
    int numberOfPatients;
    scanf("%d", &numberOfPatients);
    listNode *head = NULL;
    
    initializeSeverity();
    head = createList(numberOfPatients);
    head = mergeSort(head);
    printList(head);
    return 0;
}