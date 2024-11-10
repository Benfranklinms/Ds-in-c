#include <stdio.h>
#define MAX 5

struct pqueue{
    int item;
    int priority;
};

struct pqueue pq[MAX];

int front = -1;
int rear = -1;
int i;
int loc;

void enqueuePq(int item, int priority){
    if(front == 0 && rear == MAX - 1){
        printf("Queue overflow");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;

        pq[rear].item = item;
        pq[rear].priority = priority;
    }
    else{
        for(i = rear; i >= front; i--){
            if(pq[i].priority > priority){
                pq[i + 1] = pq[i];
            }
            else{
                break;
            }
        }
        loc = i + 1;
        pq[loc].item = item;
        pq[loc].priority = priority;
        rear++;
    }
}

void dequeuePq(){
    if(front == -1 && rear == -1){
        printf("Queue underflow\n");
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}


void display(){
    int i;
    for(i = front; i <= rear; i++){
        printf("item : %d\t priority : %d\n", pq[i].item, pq[i].priority);
    }
}

int main(){
    int choice, item, priority;
    int i;
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while(1){
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter item : ");
                scanf("%d", &item);
                printf("Enter priority : ");
                scanf("%d", &priority);
                enqueuePq(item, priority);
                break;
            case 2:
                dequeuePq();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Enter correct options ");
        }
    }
}