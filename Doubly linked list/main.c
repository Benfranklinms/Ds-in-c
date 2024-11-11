#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node node;

node *createnode(int item)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->data = item;
    newnode->next = NULL;
    return newnode;
}

void insertFront(node **head, int item)
{
    node *newnode = createnode(item);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;
}

void insertEnd(node **head, int item)
{
    node *newnode = createnode(item);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertLoc(node **head, int item, int pos)
{
    int i = 1;
    if (pos < 1)
    {
        printf("Position should be greater than 1");
        return;
    }
    if (pos == 1)
    {
        insertFront(head, item);
        return;
    }
    node *newnode = createnode(item);
    node *temp = *head;
    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Wrong position");
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void deleteFront(node **head)
{
    if (*head == NULL)
    node *temp = *head;
    {
        printf("List is already empty");
        return;
    }
    else
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteEnd(node **head)
{
    node *temp = *head;
    if (*head == NULL)
    {
        printf("List is already empty");
        return;
    }
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteLoc(node **head, int position)
{
    int i;
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }
    node *temp = *head;
    if (position == 1)
    {
        deleteFront(head);
        return;
    }
    for (i = 1; temp != NULL && i < position; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position is greater than the number of nodes.\n");
        return;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void display(node **head)
{
    node *temp = *head;
    while (temp != NULL)
    {
        printf(" -> %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    int choice, data, pos;
    while (1)
    {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            insertFront(&head, data);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 3:
            printf("Enter data : ");
            scanf("%d", &data);
            printf("Enter position : ");
            scanf("%d", &pos);
            insertLoc(&head, data, pos);
            break;
        case 4:
            deleteFront(&head);
            break;
        case 5:
            deleteEnd(&head);
            break;
        case 6:
            printf("Enter position : ");
            scanf("%d", &pos);
            deleteLoc(&head, pos);
            break;
        case 7:
            display(&head);
            break;
        case 8:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}