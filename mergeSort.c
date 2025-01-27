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

void merge(int *arr,int left,int mid,int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int* arr1 = (int*)malloc(size1*sizeof(int));
    int* arr2 = (int*)malloc(size2*sizeof(int));

    int pivotIndex = left;

    for(int index = 0;index<size1;index++)
    {
        arr1[index] = arr[pivotIndex++];
    }

    for(int index = 0;index<size2;index++)
    {
        arr2[index] = arr[pivotIndex++];
    }

    pivotIndex = left;
    int index1 = 0,index2 = 0;

    while(index1<size1 && index2<size2)
    {
        if(arr1[index1] < arr2[index2])
        {
            arr[pivotIndex++] = arr1[index1++];
        }
        else
        {
            arr[pivotIndex++] = arr2[index2++];
        }
    }

    while(index1<size1)
    {
        arr[pivotIndex++] = arr1[index1++];
    }

    while(index2<size2)
    {
        arr[pivotIndex++] = arr2[index2++];
    }


    free(arr1);
    free(arr2);
}

void mergeSort(int* arr,int left,int right)
{
    if(left>=right)
    return;
    int mid = left + (right - left)/2 ;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
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
    mergeSort(arr,0,size-1);
    printf("Array After Merge Sort Operation: ");
    printArray();
    return 0;
}