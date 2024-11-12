#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow!!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Element enqueued in the queue is %d\n", item);
    }
}

int dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Queue underflow!!\n");
        return -1;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        return item;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter an option(1-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            if (item != -1)
            {
                printf("%d is the dequeued element\n", item);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid option!!\n");
        }
    }
}
