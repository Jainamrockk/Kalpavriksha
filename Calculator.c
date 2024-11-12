/*
Problem 1 :  
Calculator Problem Statement
 Design a console-based calculator program in C that accepts mathematical
expressions as input in the form of strings.

 The program should evaluate the expression and return the result. Supported
operations include addition (+), subtraction (-), multiplication (*), and division (/).
 The program should handle integer operations and output the result as an integer,
even if the result of division has a remainder.
Requirements
 The input should be a mathematical expression in the form of a string.
 The input string contains integers and operators (+, -, *, /) only.
 The program should handle whitespace between numbers and operators, which
should be ignored.
 The program should output the result of the expression as an integer.
 If division by zero occurs, the program should display an error message: &#39;Error:
Division by zero.&#39;
 If the input expression is invalid (e.g., contains invalid characters), the program
should display an error message: &#39;Error: Invalid expression.&#39;
 The program should follow the order of operations (DMAS), where multiplication
and division are performed before addition and subtraction.
 Consider handling precedence and associativity while evaluating the expression.
Input Format:
The input will consist of a single line containing the mathematical expression as a
string.
Output Format:
The output will be a single integer or an error message depending on the
evaluation result.
Test Cases:
Input: &quot;3 + 5 * 2&quot;
Output: 13
Input: &quot;3 + a * 2&quot;
Output: Error: Invalid expression.

*/





#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int n = 0;

int isDigit(char c) 
{
    // Function to check if a character is a digit or not
    return c>='0' && c<='9';
}

int isOperator(char c)
{
    // Function to check if a character is an operator or not
    return c=='+' || c=='-' || c=='*' || c=='/';
}

void InvalidExpression()
{
    // Function to print error message
    printf("Error: Invalid expression.\n");
    exit(0);
}
int Operation(int a,int b , char op)
{
    int ans  = 0;
switch(op)
{
    case '+':
    ans = a+b;
    break;
    case '-':
    ans = a-b;
    break;
    case '*':
    ans = a*b;
    break;
    case '/':
    if(b==0)
    {
        printf("Error: Division by zero.\n");
        exit(0);
    }
    ans = a/b;
    break;
}
 return ans;

}
int precedence(char c)
{
    return c=='+' || c=='-' ? 1 : 2;
}

int Calculate(char expression[])
{
    int i = 0,head_val = -1,head_op = -1,LastCharWasOp = 1;
    int values[100];
    char operators[100];

    while(expression[i]!='\0')
    {
        while(expression[i]==' ')
        {
            i++;
            continue;
        }
        if(isDigit(expression[i]))
        {
            int num = 0;
            while(i<n && isDigit(expression[i]))
            {
                num = num*10 + (expression[i]-'0');
                i++;
            }
            values[++head_val] = num;
            LastCharWasOp = 0;
        }
        else if(isOperator(expression[i]))
        {
            if(LastCharWasOp)
            {
                InvalidExpression();
            }
            while(head_op!=-1 && precedence(expression[i]) <= precedence(operators[head_op]))
            {
                int b = values[head_val--];
                int a = values[head_val--];
                char op = operators[head_op--];
                //application of operation
                values[++head_val] = Operation(a,b,op);

            }
            operators[++head_op] = expression[i];
            i++;
            LastCharWasOp = 1;
        }
        else
        {
            InvalidExpression();
        }
    }
    if (LastCharWasOp) {
        InvalidExpression();
    }

    while(head_op != -1)
    {
        int b = values[head_val--];
        int a = values[head_val--];
        char op = operators[head_op--];
        //application of operation
        values[++head_val] = Operation(a,b,op);
    }
    return values[head_val];
}
int main()
{
    char expression[100];
    fgets(expression, 100, stdin);
    n = strlen(expression);
    expression[strcspn(expression, "\n")] = 0; // To Remove newline character
    int ans = Calculate(expression);
    printf("%d\n", ans);
    return 0;
}