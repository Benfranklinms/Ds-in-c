#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *createnode(int item) {
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL) {
        printf("Can't allocate memory");
    }
    newnode -> data = item;
    newnode -> next = NULL;
    return newnode;
}

void enqueue(node **front, node **rear, int item) {
    node *newnode = createnode(item);
    if(*rear == NULL) {
        *front = *rear = newnode;
    }
    else {
        (*rear) -> next = newnode;
        *rear = newnode;
    }
}

void dequeue(node **front, node **rear) {
    if(*front == NULL) {
        printf("Queue empty");
        *rear = NULL;
    }
    else {
        node *temp = *front;
        *front = (*front) -> next;
        free(temp);
    }
}

void display(node *front) {
    int i;
    for(i = 0; front != NULL; i++) {
        printf("%d -> ", front -> data);
        front = front -> next;
    }
    printf("NULL");
}

int main() {
    int choice, i, item;
    node *front = NULL;
    node *rear = NULL;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter an item : ");
                scanf("%d", &item);
                enqueue(&front, &rear, item);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                return 0;
            default:
                printf("Enter correct option");
        }
    }
}