#include<stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int n, int x)
{
    if(rear == n-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
        printf("%d inserted successfully\n", x);
    }
}

void dequeue(int n)
{
    int x;
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = queue[front];
        front++;
        printf("%d deleted from the queue\n", x);
    }
}

void display(int n)
{
    int i;
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is: ");
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, choice, x;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                enqueue(n, x);
                break;
            case 2:
                dequeue(n);
                break;
            case 3:
                display(n);
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
