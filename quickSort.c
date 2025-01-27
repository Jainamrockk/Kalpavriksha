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

void swap(int *num1,int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *arr,int left,int right)
{
    int pivotIndex = left;

    while(left<right)
    {
        while(left<right && arr[left]<arr[pivotIndex])
        {
            left++;
        }

        while(left<right && arr[right]>=arr[pivotIndex])
        {
            right--;
        }

        if(left<right)
        {
            swap(&arr[left],&arr[right]);
        }
    }
    swap(&arr[left],&arr[pivotIndex]);
    return pivotIndex;
}

void quickSort(int* arr,int left,int right)
{
    if(left>=right)
    return;
    int pivot = partition(arr,left,right);
    quickSort(arr,left,pivot-1);
    quickSort(arr,pivot+1,right);
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
    quickSort(arr,0,size-1);
    printf("Array After Merge Sort Operation: ");
    printArray();
    return 0;
}