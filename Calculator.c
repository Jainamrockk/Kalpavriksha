#include<stdio.h>
#include<stdlib.h>

size_t str_length = 0;

int isDigit(char c) 
{
    
    return c>='0' && c<='9';
}

int isOperator(char c)
{
   
    return c=='+' || c=='-' || c=='*' || c=='/';
}

void invalidExpression()
{
    
    printf("Error: Invalid expression.\n");
    exit(0);
}
int applyOperator(int a,int b , char op)
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
int getPrecedence(char c)
{
    return c=='+' || c=='-' ? 1 : 2;
}

int evaluateExpression(char *expression)
{
    int i = 0,head_val = -1,head_op = -1,lastCharWasOp = 1;
   int values[str_length];
   char operators[str_length];

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
            while(i<str_length && isDigit(expression[i]))
            {
                num = num*10 + (expression[i]-'0');
                i++;
            }
            values[++head_val] = num;
            lastCharWasOp = 0;
        }
        else if(isOperator(expression[i]))
        {
            if(lastCharWasOp)
            {    
                invalidExpression();
            }
            while(head_op!=-1 && getPrecedence(expression[i]) <= getPrecedence(operators[head_op]))
            {
                int b = values[head_val--];
                int a = values[head_val--];
                char op = operators[head_op--];
                values[++head_val] = applyOperator(a,b,op);

            }
            operators[++head_op] = expression[i];
            i++;
            lastCharWasOp = 1;
        }
        else
        { 
            invalidExpression();
        }
    }
    if (lastCharWasOp) {
        invalidExpression();
    }

    while(head_op != -1)
    {
        int b = values[head_val--];
        int a = values[head_val--];
        char op = operators[head_op--];
      
        values[++head_val] = applyOperator(a,b,op);
    }
    
  
    return values[head_val];
}


void solveExpression()
{
    size_t buffer_size = 10;
    
    char* expression = malloc(buffer_size);
    if (expression == NULL) {
       
        invalidExpression();
        
    }
    char currentChar;
    while((currentChar=getchar())!='\n' && currentChar!= EOF)
    {
        if(str_length+1>= buffer_size)
        {
            buffer_size *= 2;
            expression = realloc(expression, buffer_size);
              if (expression == NULL) {
                 
                 invalidExpression();
                 }
        }
        expression[str_length++] = currentChar;
    }
    expression[str_length] = '\0';
    
    int ans = evaluateExpression(expression);
    printf("%d\n", ans);
    free(expression);
}

int main()
{
    solveExpression();
    return 0;
}