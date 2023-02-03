#include <stdio.h>
#include<math.h>

int insert(int a[20], int n);
int delete(int a[20], int n);
int search(int a[20],int n);

int insert(int a[20], int n)
{
    int index,key;
    printf("At which place you want to insert your element:\n ");
    scanf("%d", &index);
    printf("And the value of that element in intergers:\n ");
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

int delete(int a[20], int n){
    int index;
    printf("At which place you want to delete your element:\n ");
    scanf("%d", &index);
    for(int i = index ; i <= n; i++)
    {
        a[i] = a[i+1];
    }
    for (int i = 0; i < n-1; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int search(int a[20],int n)
{
    int key;
     printf("which element you want to search: \n");
    scanf("%d", &key);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("The index of the your element is %d \n", i+1);
            return 1;
        }
        
    }
    printf("element not found");
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
    case 3:
        search(a,n);
        break;
    }
     
    return 0;
}