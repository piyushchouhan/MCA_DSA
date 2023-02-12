// implementation using C ( .c file ) to performing the following operations on a stack of size n
#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    printf("Item pushed to stack\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped item is: %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: \n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main()
{
    int choice, item, k;
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of elements to push: ");
            scanf("%d", &k);
            for (int i = 0; i < k; i++)
            {
                printf("Enter item: ");
                scanf("%d", &item);
                push(item);
            }
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
