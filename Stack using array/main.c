#include <stdio.h>

#define MAX 5

int stack[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("Stack overflow!!");
    }
    else{
        top++;
        stack[top]=item;
        printf("Element push in stack is %d",item);
    }
}
int pop(){
    int item;
    if(top==-1){
        printf("Stack underflow!!");
    }
    else{
        item=stack[top];
        top--;
        return item;
    }
}
int peek(){
    if(top==-1){
        printf("Stack underflow!!");
        return -1;
    }
    else
        return stack[top];
}
void display(){
    int i;
    if(top==-1){
        printf("Stack underflow!!");
    }
    else{
         printf("Elements in stack are:\n");
         for(i=top;i>=0;i--){
            printf("%d\n",stack[i]);
         }
    }
}
int main(){
    int choice,item,i;
    while(1){
        printf("\nStack operations!!\n");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
              printf("Enter the element to push:");
              scanf("%d",&item);
              push(item);
              break;
            case 2:
              item=pop();
              if(item!=-1){
                printf("%d popped from stack",item);
              }
              break;
            case 3:
              item=peek();
              if(item!=-1){
                printf("%d is the top element in the stack",item);
              }
              break;
            case 4:
              display();
              break;
            default:
                printf("Invalid choice!!!");
        }
    }
    return 0;
}