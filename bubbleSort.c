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

void bubbleSort()
{
    for (int index = size - 1; index > 0; index--)
    {
        int isSwapped = 0;
        for (int cmpIndex = 0; cmpIndex <= index - 1; cmpIndex++)
        {
            if (arr[cmpIndex] > arr[cmpIndex + 1])
            {
                swap(&arr[cmpIndex], &arr[cmpIndex + 1]);
                isSwapped = 1;
            }
        }
        if(isSwapped == 0)
        break;
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
    bubbleSort();
    printf("Array After Bubble Sort Operation: ");
    printArray();
    return 0;
}