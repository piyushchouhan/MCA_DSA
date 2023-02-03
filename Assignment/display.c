#include <stdio.h>

int main()
{
    int n;
    n = 10;
    int index;
    int a[10];
    printf("\n Enter the numbers in array: ");
    for (int i = 0; i < n; i++)
    {
        printf("\n Number %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Element of which of index you want to print: ");
    scanf("%d", &index);
    printf("\n");
    printf("%d", a[index]);

    return 0;
}