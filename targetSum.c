#include<stdio.h>
#include<stdlib.h>
int size;
int* arr;
void getIntegerArray(char* input)
{
    int value = 0;
    int isNegative = 0,index=0;
   while(*input!='\0')
   {
        char ch = *input;
        if(ch == '-')
        {
            isNegative = 1;
        }
        else if(ch>='0' && ch<='9')
        {
            value = value*10 + ch - '0';
        }
        if(ch == ',' || ch == ']')
        {
            if(isNegative == 1)
            {
                value = value*(-1);
                isNegative = 0;
            }
            arr[index++] = value;
            value = 0;
        }
        input++;
   }
   size = index;
}


void printArr(int* subArr,int size)
{
    for(int index= 0;index<size;index++)
    {
        printf("%d ",subArr[index]);
    }
    printf("\n");
}


void printCombinations(int* arr,int index,int* subArr,int target,int currSum,int subArrSize)
{
    if(currSum == target)
    {
        printArr(subArr,subArrSize);
        return;
    }
    else if(currSum > target)
    return;

    for(int currIndex = index;currIndex<size;currIndex++)
    {
        subArr[subArrSize] = arr[currIndex]; 
        if(currSum == -1)
        currSum = 0;
        printCombinations(arr,currIndex,subArr,target,currSum+arr[currIndex],subArrSize+1);
    }
}

int main()
{
    int target;
    arr = (int*)calloc(100,sizeof(int));
    char* input = (char*)malloc(1000*sizeof(char));
    scanf("%s",input);
    scanf("%d",&target);
    size = 0;
    getIntegerArray(input);
    int* subArr = (int*)malloc(size*sizeof(int));
    printCombinations(arr,0,subArr,target,-1,0);
    return 0;
}