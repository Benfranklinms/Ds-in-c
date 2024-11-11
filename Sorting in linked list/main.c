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

void bubbleSort(node *head) {
    node *ptr;
    node *lptr = NULL;
    int swapped = 1;
    if(head == NULL) {
        return;
    }
    else {
        while(swapped) {
            swapped = 0;
            ptr = head;
            while(ptr -> next != lptr) {
                if(ptr -> data < ptr -> next -> data) {
                    int temp;
                    temp = ptr -> data;
                    ptr -> data = ptr -> next -> data;
                    ptr -> next -> data = temp;
                    swapped = 1;
                }
                ptr = ptr -> next;
            }
            lptr = ptr;
        }
    }
}

