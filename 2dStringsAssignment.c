#include<stdio.h>
#include<stdlib.h>


int totalRows,totalColumns;
char***nameMatrix;


void inputConstraints()
{
    printf("Enter number of rows:");
    scanf("%d",&totalRows);
    printf("Enter number of columns:");
    scanf("%d",&totalColumns);   
}

void initializeMatrix()
{
     nameMatrix = (char***)malloc(totalRows*sizeof(char**));
    for(int row = 0;row<totalRows;row++)
    {
        nameMatrix[row] = (char**)malloc(totalColumns*sizeof(char *));
        for(int column = 0;column<totalColumns;column++)
        {
            nameMatrix[row][column] = (char*)malloc(51*sizeof(char));
        }
    }
}

void inputNameMatrix()
{

    printf("Enter the Names:\n");
   for(int row = 0;row<totalRows;row++)
   {
       for(int column = 0;column<totalColumns;column++)
       {
           printf("Name at (%d,%d):",row,column);
           scanf("%s",nameMatrix[row][column]);
       }
   }
    
}

int countVowel()
{
    int vowelArray[10] = {'a','e','i','o','u','A','E','I','O','U'};
    int vowelNameCount = 0;
    for(int row = 0;row<totalRows;row++)
    {
        for(int column = 0;column<totalColumns;column++)
        {
            for(int count = 0;count<10;count++)
            {
                if(nameMatrix[row][column][0] == vowelArray[count])
                {
                    vowelNameCount++;
                }
            }
        }
    }
    
    return vowelNameCount;
}


int lenName(char* name)
{
    int length = 0;
    while(name[length]!='\0') length++;
    return length;
}


int evaluateMaxLengthName()
{
    int maxLengthName = 0;
    
    for(int row=0;row<totalRows;row++)
    {
        for(int column=0;column<totalColumns;column++)
        {
            int Length = lenName(nameMatrix[row][column]);
            if(Length>maxLengthName)
            maxLengthName = Length;
        }
    }
    return maxLengthName;
}
void printNames()
{
    printf("The 2D array of names is:\n");
    for(int row=0;row<totalRows;row++)
    {
        for(int column=0;column<totalColumns;column++)
        {
            printf("%s ",nameMatrix[row][column]);
        }
        printf("\n");
    }
}

void printVowelName(int vowelNameCount)
{
    printf("Number of names starting with a vowel:%d\n",vowelNameCount);
}

void printMaxLengthName(int maxLengthName)
{
    printf("The longest name:");
     for(int row=0;row<totalRows;row++)
    {
        for(int column=0;column<totalColumns;column++)
        {
            if(lenName(nameMatrix[row][column]) == maxLengthName)
            {
                printf("%s ",nameMatrix[row][column]);
                return;
            }
        }
      
    }
}

void deallocateResources()
{
    for(int row = 0;row<totalRows;row++)
    {
        
        for(int column = 0;column<totalColumns;column++)
        {
            free(nameMatrix[row][column]);
        }
        free(nameMatrix[row]);
    }
    free(nameMatrix);
}

void solution()
{
    inputConstraints();
    initializeMatrix();
    inputNameMatrix();
    printNames();
    int vowelNameCount = countVowel();
    printVowelName(vowelNameCount);
    int maxLengthName = evaluateMaxLengthName();
    printMaxLengthName(maxLengthName);
    deallocateResources();
}
int main()
{
    solution();
    return 0;
}