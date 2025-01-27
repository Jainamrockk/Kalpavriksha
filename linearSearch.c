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

int linearSearch(int* arr,int target)
{
    int ans = -1;
    for(int index=0;index<size;index++)
    {
        if(arr[index] == target)
        {
            ans = index;
            break;
        }
    }
    return ans;
}



int main()
{
    int target;
    arr = (int *)malloc(1000 * sizeof(int));
    printf("Enter the array Elements:");
    createArray();
    printf("Enter the target Element:");
    scanf("%d",&target);
    int ans = linearSearch(arr,target);
    if(ans == -1)
    printf("Element is not present\n");
    else
    printf("Element is present at index: %d\n",ans);
 
    return 0;
}