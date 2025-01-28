#include<stdio.h>
#include<stdlib.h>

int size;
int* arr;
int* countArr;

void createArray()
{
    size = 0;
    arr = (int*)malloc(1000*sizeof(int));
    while(1)
    {
        int value;
        scanf("%d",&value);

        arr[size++] = value;

        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }

    arr = (int*)realloc(arr,size*sizeof(int));
}


int findMax()
{
    int maxElement = 0;
    for(int index = 0;index<size;index++)
    {
        countArr[arr[index]] = 1;
        if(maxElement<arr[index])
        maxElement = arr[index];
    }
    return maxElement+1;
}


void findMaxDifference(int countSize)
{
    int left = 0;
    int maxDifference = 0;
    while(countArr[left]!=1)
    left++;

    int right = left+1;

    while(right<countSize)
    {
        while(right<countSize && countArr[right]!=1)
        right++;
        if(right<countSize)
        {
            int diff = right - left;
            if(diff > maxDifference)
            maxDifference = diff;
            left = right;
            right++;
        }
    }

    printf("%d",maxDifference);

}
int main()
{
    createArray();
    if(size<=1)
    {
        printf("0");
        return 0;
    }
    countArr = (int*)malloc((10000)*sizeof(int));
    int countSize = findMax();

    findMaxDifference(countSize);
    return 0;
}