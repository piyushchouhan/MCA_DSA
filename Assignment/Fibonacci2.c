//PROGRAM TO FIND Nth TERM OF FIBONACCI SERIES (TAIL RECURSIVE).

#include <stdio.h>
#include <math.h>

int FibonacciTailRecursion(int n, int x , int y)
{
    if (n == 1)
    {
        return x;
    }
    return FibonacciTailRecursion(n-1,y,x+y);
}

int main()
{
    int n,Value;
    printf("Eneter the nth no. you want to print: ");
    scanf("%d", &n);
    Value = FibonacciTailRecursion(n,0,1);
    printf("The number at index %d in the Fibonacci sequence is %d. \n", n, Value);
    return 0;
}
