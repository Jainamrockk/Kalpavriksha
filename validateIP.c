/*
Problem Statement: Validate IPv4 Address 
Objective:
Write a program in C to validate whether a given string is a valid IPv4 address.
Requirements:
1. An IPv4 address consists of four decimal numbers separated by dots (.).
Each number must be in the range 0 to 255.
Leading zeros are not allowed unless the number is exactly 0.
 Each number should be composed of digits only.
Example of valid IPv4 addresses: 192.168.0.1, 127.0.0.1.
Example of invalid IPv4 addresses: 256.256.256.256, 192.168.01.1, 192.168..1.
2. Constraints:
The input string will be a maximum of 15 characters.
 There will be no whitespace in the input.
Input Format:
A single string representing the IPv4 address.
Output Format:
A single line of output:
• Print "Valid" if the input is a valid IPv4 address.
• Print "Invalid" if the input is not a valid IPv4 address.
Example:
Input 1:
192.168.1.1
Output 1:
Valid
Input 2:
256.256.256.256
Output 2:
Invalid
Input 3:
192.168.01.1
Output 3:
Invalid
Input 4:
192.168..1
Output 4:
Invalid

*/

#include<stdio.h>
#include<stdlib.h>

char* input;

void inputSentence()
{
    input = (char*)malloc(16*sizeof(char));
    scanf("%[^\n]",input);
    getchar();
}

void isValid()
{
    int dotCount = 0;
    int number = -1;
    int lastWasDot = 1;
    while(*input!='\0')
    {
        char ch = *input;
        if(ch >= '0' && ch<='9')
        {
            if(number == -1)
            number = 0;
            number = number*10+ch-'0';
            if(lastWasDot == 1 && number == 0)
            {
                printf("Not Valid\n");
                return;
            }
            lastWasDot = 0;

        }
        else if(ch == '.')
        {
            dotCount++;
            if(number>255 || number<0)
            {printf("Not Valid\n");
                return;
            }
            number = -1;
            lastWasDot = 1;
        }
        else
        {
            printf("Not Valid\n");
                return;
        }
        input++;
    }

    if(dotCount !=3)
    {printf("Not Valid\n");}
    else
    printf("Valid\n");
}
void solution()
{
    inputSentence();
    isValid();
}

int main()
{
    solution();
    return 0;
}