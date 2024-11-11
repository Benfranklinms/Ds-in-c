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
    else {
        newnode -> data = item;
        newnode -> next = NULL;
        return newnode;
    }
}

void insert(node **head, int item) {
    node *temp = *head;
    node *newnode = createnode(item);
    if(newnode == NULL) {
        return;
    }
    if(*head == NULL) {
        *head = newnode;
    }
    else {
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

node *merge(node *head1, node *head2) {
    node *mergehead = NULL;
    if(head1 == NULL) {
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    if(head1 -> data <= head2 -> data) {
        mergehead = head1;
        mergehead -> next = merge(head1 -> next, head2);
    }
    else {
        mergehead = head2;
        mergehead -> next = merge(head1, head2 -> next);
    }
    return mergehead;
}

void display(node *head) {
    node *temp = head;
    int i;
    for(i = 0; temp != NULL; i++) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL");
}


int main() {
    node *head1 = NULL, *head2 = NULL, *mergehead = NULL;
    int choice;
    int item;
    while(1) {
        printf("\n1. Insert in list 1\n");
        printf("2. Insert in list 2\n");
        printf("3. Merge the lists\n");
        printf("4. Exit\n");
        printf("\nEnter a choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the item to be inserted in list 1 : ");
                scanf("%d", &item);
                insert(&head1, item);
                display(head1);
                break;
            case 2:
                printf("\nEnter the item to be inserted in list 2 : ");
                scanf("%d", &item);
                insert(&head2, item);
                display(head2);
                break;
            case 3:
                mergehead = merge(head1, head2);
                display(mergehead);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}