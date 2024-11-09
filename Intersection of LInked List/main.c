#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int i, j;

typedef struct node node;

node *createnode(int item){
    node *newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory error");
        return NULL;
    }
    newnode -> data = item;
    newnode -> next = NULL;
    return newnode;
}

void insertEnd(node **head, int item){
    node *newnode = createnode(item);
    node *temp = *head;
    if(newnode == NULL){
        printf("Can't allocate memory");
    }
    else if(*head == NULL){
        *head = newnode;
    }

    else{
        for(i = 0; temp -> next != NULL; i++){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}

int exist(node *head, int item){
    node *temp = head;
    while(temp != NULL){
        if(temp -> data == item){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

struct node *getIntersection(int set1[], int size1, int set2[], int size2){
    node *intersection = NULL;

    for(i = 0; i < size1; i++){
        for(j = 0; j < size2; j++){
            if(set1[i] == set2[j] && !exist(intersection, set1[i])){
                insertEnd(&intersection, set1[i]);
                break;
            }
        }
    }
    return intersection;
}

void display(node *head){
    node *temp = head;

    for(i = 0; temp != NULL; i++){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){

    int s1[] = {10, 20, 30, 40};
    int s2[] = {30, 40, 50};

    int size1 = sizeof(s1) / sizeof(s1[0]);
    int size2 = sizeof(s2) / sizeof(s2[0]);

    node *intersection = getIntersection(s1, size1, s2, size2);

    printf("Intersection of s1 and s2 is : \n");
    display(intersection);
}