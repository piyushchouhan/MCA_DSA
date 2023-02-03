#include <stdio.h>
#include<math.h>

int insert(int a[20], int n);
int delete(int a[20], int n);
int search(int a[20],int n);

int insert(int a[20], int n)
{
    int index,key;
    printf("At which place you want to insert your element: ");
    scanf("%d", &index);
    printf("And the value of that element in intergers: ");
    scanf("%d", &key);

    for(int i = n-1 ; i >= index; i--)
    {
        a[i] = a[i-1];
    }
    a[index] = key;

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}







int main()
{
    int n;
    n = 5;
    int action;
    int a[20];
    printf("\n Enter the numbers in array: ");
    for(int i = 0 ; i < n; i++)
    {
        printf("\n Number %d: ", i);
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");


    printf("input 1 for inserting your value at nth location!\n");
    printf("input 2 for deleting your nth element from list!\n");
    printf("input 3 for searching in the list!\n");

    scanf("%d", &action);

    switch (action)
    {
    case 1:
        insert(a,n);
        break;
    case 2:
        delete(a,n);
        break;
    // case 3:
    //     search(a,n);
    //     break;
    }
     
    return 0;
}