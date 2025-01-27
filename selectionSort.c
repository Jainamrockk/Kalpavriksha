#include <stdio.h>
#include <stdlib.h>

int size;
int *arr;
void createArray()
{
    int value;
    size = 0;
    while (1)
    {
        scanf("%d", &value);
        arr[size++] = value;
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
    }

    arr = (int *)realloc(arr, size * sizeof(int));
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selectionSort()
{
    for (int index = 0; index<size-1; index++)
    {
        int minIndex = index;
        for(int cmpIndex=index+1;cmpIndex<size;cmpIndex++)
        {
            if(arr[cmpIndex]<arr[minIndex])
            minIndex = cmpIndex;
        }       
        swap(&arr[index],&arr[minIndex]);
    }
}

void printArray()
{
    for (int index = 0; index < size; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

int main()
{
    arr = (int *)malloc(1000 * sizeof(int));
    printf("Enter the array Elements:");
    createArray();
    selectionSort();
    printf("Array After Selection Sort Operation: ");
    printArray();
    return 0;
}