#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue_front(int item)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow !!");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[front] = item;
    }
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
        queue[front] = item;
    }
    else
    {
        front = front - 1;
        queue[front] = item;
    }
}
void enqueue_rear(int item)
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow !!");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = item;
    }
}
int dequeue_front()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("Underflow !!");
    }
    else if (front == rear)
    {
        item = queue[front];
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        item = queue[front];
        front = 0;
    }
    else
    {
        item = queue[front];
        front = front + 1;
    }
    return item;
}
int dequeue_rear()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("Underflow !!");
    }
    else if (front == rear)
    {
        item = queue[rear];
        front = rear = -1;
    }
    else if (rear == 0)
    {
        item = queue[rear];
        rear = MAX_SIZE - 1;
    }
    else
    {
        item = queue[rear];
        rear = rear - 1;
    }
}
int display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Underflow !!");
    }
    else
    {
        printf("Elements in the queue are : \n");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            printf("\n%d", queue[i]);
        }
        printf("\n%d", queue[i]);
    }
}
int main()
{
    int choice, item, i;
    while (1)
    {
        printf("\n1.Enqueue form front\n2.Enqueue from rear\n3.Dequeue from front\n4.Dequeue from rear\n5.Display\n6.Exit");
        printf("\nEnter an option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue from front:");
            scanf("%d", &item);
            enqueue_front(item);
            break;
        case 2:
            printf("Enter element to enqueue from rear:");
            scanf("%d", &item);
            enqueue_rear(item);
            break;
        case 3:
            item = dequeue_front();
            if (item != -1)
                printf("%d is the dequeued element", item);
            break;
        case 4:
            item = dequeue_rear();
            if (item != -1)
                printf("%d is the dequeued element", item);
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;

        default:
            printf("Invalid option!!");
            break;
        }
    }
}