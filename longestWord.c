#include<stdio.h>
#include<stdlib.h>
int maxLength = 0;
int lenWord(char* word)
{
    int wordIndex = 0;
    int length = 0;
    while(word[wordIndex]!='\0')
    {
        if((word[wordIndex]>='a' && word[wordIndex]<='z') ||(word[wordIndex]>='A' && word[wordIndex]<='Z') || (word[wordIndex]>='0' && word[wordIndex]<='9'))
        {
            length++; 
        }
        else
        {
        if(length>maxLength)
        {
            maxLength = length;
            length = 0;
        }
        }
        wordIndex++;
    }
    return length;
}
void inputSentence()
{
    char* sentence[100];
    int wordIndex = 0;
    while(1)
    {
        char* word = (char*)malloc(100*sizeof(char));
        scanf("%s",word);
        int wordLength = lenWord(word);
        if(wordLength>maxLength)
        {
            maxLength = wordLength;
        }
        sentence[wordIndex++] = word;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)
        break;
    }
}
void printMaxWord()
{
    printf("%d\n",maxLength);
}
void solution()
{
    inputSentence();
    printMaxWord();
}

int main()
{
    solution();
    return 0;
}