#include<stdio.h>
#include<stdlib.h>

int size,maxCount,maxIndex;
int* arr;

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


void countOnes(int maxOperation)
{
    maxCount = 0 ;
    for(int index = 0;index<size;index++)
    {
        int count=0;
        int cmpIndex = index;
        int window = maxOperation;
        while(window>=0 && cmpIndex<size )
        {
            if(arr[cmpIndex] == 0)
            window--;
            count++;
            cmpIndex++;
        }
        if(window<0)
        count--;
        if(count > maxCount)
        maxCount = count;
    }
}

int main()
{
    int maxOperation;
    createArray();
    scanf("%d",&maxOperation);
    countOnes(maxOperation);
    printf("%d",maxCount);

}