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

int search(node *head, int item) {
    node *temp = head;
    int position;
    position = 0;
    while(temp != NULL) {
        if (temp -> data == item) {
            return position;
        }
        else {
            temp = temp -> next;
            position++;
        }
    }
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
    node *head = NULL;
    int choice, i, item;
    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter an item : ");
                scanf("%d", &item);
                insert(&head, item);
                break;
            case 2:
                printf("\nEnter element to search : ");
                scanf("%d", &item);
                int find = search(head, item);
                if(find != -1) {
                    printf("Element found at position %d\n", find + 1);
                }
                else{
                    printf("Element not found\n");
                }
                break;
            case 3:
                display(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

}