#include <stdio.h>
void printSpaces(int spaces)
{
     for(int space = 0;space<=spaces;space++)
        {
            printf(" ");
        }
}
void upperPattern(int rowDigits)
{
      for(int column = 1;column<=rowDigits;column++)
        {
            printf("%d",column);
        }
}
void lowerPattern(int rowDigits,int input,int row)
{
     for(int column = rowDigits;column>=1;column--)
        {
            printf("%d",column);
        }
}
void printPattern(int input)
{
    int spaces = 2*input - 1,totalRows = 2*input-1;
    int rowDigits = 0;
    for(int row = 1;row<=totalRows;row++)
    {
        if(row<=input)
        {
            spaces-=2;
            rowDigits++;
        }
        else
        {
            spaces+=2;
            rowDigits--;
        }
        upperPattern(rowDigits);
        printSpaces(spaces);
        lowerPattern(rowDigits,input,row);
        printf("\n");
    }
}
void inputFunction()
{
    int input;
    scanf("%d", &input);
    if(input<=0)
    {
        printf("Input should be greater than 0\n");
        return;
    }
    printPattern(input);
}

int main()
{
  
    inputFunction();
    return 0;

}