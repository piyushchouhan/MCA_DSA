//ROGRAM TO FIND Nth TERM OF FIBONACCI SERIES (NON-RECURSIVE).

#include <stdio.h>
#include <math.h>

int FiboNonRecursive(int n)
{
    int x = 0;
    int y = 1;
    for(int i = 1; i < n; i++)
    {
        y = x + y;
        x = y - x;
    }

    return x;
}

int main()
{
    int n, Value;
    printf("Eneter the nth no. you want to print: ");
    scanf("%d", &n);
    Value = FiboNonRecursive(n);
    printf("The number at index %d in the Fibonacci sequence is %d. \n", n, Value);
    return 0;
}
