#include <stdio.h>
#include <stdlib.h>


// Define a structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
};

struct node node;

node *createNode(int item){
  node *newnode = (node*)malloc(sizeof(node));
  newnode -> data = item;
  newnode -> next = NULL;
  return newnode;
}

void insertFront(int item, node **head){
  node *newnode = createNode(item);
  if(newnode == NULL){
    printf("can't allocate memory");
  }
  else{
    newnode -> next = *head;
    *head = newnode;
  }
}

void insertEnd(int item, node **head){
  node *newnode = createNode(item);
  if(newnode == NULL){
    printf("Can't allocate memory");
  }
  if(*head == NULL){
    *head = newnode;
  }
  else{
    node *current = *head;
    while(current -> next != NULL){
      current = current -> next;
    }
    current -> next = newnode;
  }
}

void insertPosition(int item, node **head, int position){
  int i;
  node *newnode = createNode(item);
  if(position == 1){
    insertFront(item, head);
    return;
  }
  else{
    node *current = *head;
    for(i = 1; current != NULL && i < position - 1; i++){
      current = current -> next;
    }
    if(current == NULL){
      free(current);
    }
    else{
      newnode -> next = current -> next;
      current -> next = newnode;
    }
  }
}


void deleteFront(node **head){
  if(*head == NULL){
    printf("List is empty");
  }
  else{
    node *temp = *head;
    *head = temp -> next;
    free(temp);
  }
}

void deleteEnd(node **head){
  node *prev, *temp;
  if(*head == NULL){
    printf("List is empty");
  }
  else if((*head) -> next == NULL){
    temp = *head;
    *head = NULL;
  }
  else{
    while(temp -> next != NULL){
      prev = temp;
      temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
  }
}

void deletePosition(node **head, int position){
  int i;
  node *temp = *head;
  if(position == 1){
    deleteFront(head);
  }
  else{
    for(i = 1; temp != NULL && i < position - 1; i++){
      temp = temp -> next;
    }
    if(temp == NULL){
      printf("Position out of range");
    }
    else{
      node *next = temp -> next -> next;
      free(temp -> next);
      temp -> next = next;
    }
  }
}

void display(struct node **head){
  node *temp = *head;
  while(temp!= NULL){
    printf("%d -> ", temp -> data);
    temp = temp -> next;
  }
  printf("NULL\n");
}

int main(){
  node *head = NULL;
  int choice, data, pos;
   while(1){
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter you choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                insertFront(data, &head);
                break;
            case 2:
                printf("Enter data : ");
                scanf("%d", &data);
                insertEnd(data, &head);
                break;
            case 3:
                printf("Enter data : ");
                scanf("%d", &data);
                printf("Enter position : ");
                scanf("%d", &pos);
                insertPosition(data, &head, pos);
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
                deletePosition(&head, pos);
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