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

void push(node **top, int item) {
    node *newnode = createnode(item);
    newnode -> next = *top;
    *top = newnode;
}

void pop(node **top) {
    node *temp = *top;
    if(*top == NULL) {
        printf("stack is empty");
    }
    else {
        *top = (*top) -> next;
        free(temp);
    }
}

void display(node *top) {
    node *temp = top;
    int i;
    for(i = 0; temp != NULL; i++) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main() {
    int choice, i, item;
    node *top = NULL;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter an item : ");
                scanf("%d", &item);
                push(&top, item);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                return 0;
            default:
                printf("Enter correct option");
        }
    }
}
