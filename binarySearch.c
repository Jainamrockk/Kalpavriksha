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

int binarySearch(int *arr, int target)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int target;
    arr = (int *)malloc(1000 * sizeof(int));
    printf("Enter the array Elements:");
    createArray();
    printf("Enter the target Element:");
    scanf("%d", &target);
    int ans = binarySearch(arr, target);
    if (ans == -1)
        printf("Element is not present\n");
    else
        printf("Element is present at index: %d\n", ans);

    return 0;
}