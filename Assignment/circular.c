#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int element)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("Queue overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = element;
    printf("Element %d inserted successfully\n", element);
}

void delete()
{
    if (front == -1)
    {
        printf("Queue underflow\n");
        return;
    }

    int element = queue[front];
    printf("Element %d deleted\n", element);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX_SIZE; i++)
        {
            printf("%d ", queue[i]);
        }

        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insert(element);
                break;

            case 2:
                delete();
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
