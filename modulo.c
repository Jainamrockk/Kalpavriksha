#include<stdio.h>
long long base,exponent,modulo;


long long evaluateExpression()
{
    long long result = 1;
    base = base%modulo;
    while(exponent>0)
    {
        if(exponent%2)
        {
            result = (result*base)%modulo;    
        }
        exponent /=2;
        base = (base*base)%modulo;
    }
    return result;
}

void printResult(long long result)
{
    printf("Result: %lld\n",result);
}
void inputValues()
{
    printf("Input:\nBase (B): ");
    scanf("%lld",&base);
    printf("Exponent (N): ");
    scanf("%lld",&exponent);
    printf("Modulus (M): ");
    scanf("%lld",&modulo);
}

void solution()
{
    inputValues();
    long long result = evaluateExpression();
    printResult(result);
}

int main()
{
    solution();
    return 0;
}