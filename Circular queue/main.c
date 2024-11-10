#include <stdio.h>
#define MAX 5

int front = -1, rear = -1;

int cq[MAX];

void enqueue(int item){
    if((rear + 1) % MAX == front){
        printf("Overflow");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        cq[rear] = item;
    }
    else{
        rear = (rear + 1) % MAX;
        cq[rear] = item;
    }
}

void dequeue(){
    int item;
    if(front == -1 && rear == -1){
        printf("Underflow");
    }
    else if(front == rear){
        item = cq[front];
        front = -1;
        rear = -1;
    }
    else{
        item = cq[front];
        front = (front + 1) % MAX;
    }
}

void display(){
    int i;
    if(front == -1 && rear == -1) {
        printf("Underflow");
    }
    else {
        for(i = front ; i != rear; i = (i + 1) % MAX){                        //just check here
            printf("%d\t", cq[i]);
        }
        printf("%d", cq[rear]);
    }
}

int main(){
    int choice, item, i;
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter item : ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Enter correct options");
        }
    }
}