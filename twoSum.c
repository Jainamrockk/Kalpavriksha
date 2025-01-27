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

int twoSum(int* arr,int targetSum)
{
   int left = 0;
   int right = size - 1;
   while(left<right)
   {
        int sum = arr[left] + arr[right];
        if(sum == targetSum)
        return 1;
        else if(sum>targetSum)
        right--;
        else
        left++;
   }
    return 0;
}



int main()
{
    int target;
    arr = (int *)malloc(1000 * sizeof(int));
    printf("Enter the array Elements:");
    createArray();
    printf("Enter the target Sum:");
    scanf("%d",&target);
    int ans = twoSum(arr,target);
    if(ans == 0)
    printf("Sum is not present\n");
    else
    printf("Sum is Present\n");
 
    return 0;
}