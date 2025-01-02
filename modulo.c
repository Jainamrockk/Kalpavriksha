#include<stdio.h>
long long base,exponent,modulo;

//This approach is based on the basic property of modulo that (a^b)mod(c) -> ((a mod (c))^b)mod(c)
//partitioning the power into half at each iteration and taking mod each case in both even and odd powers


long long evaluateExpression()
{
    long long result = 1;
    base = base%modulo;  // Take modulo initially to handle cases where base >= modulo
    while(exponent>0)
    {                                       
        if(exponent%2)
        {
            result = (result*base)%modulo;    // If exponent is odd, multiply base with result and take modulo 
        }
        exponent /=2;  //makes it a O(logn) solution
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