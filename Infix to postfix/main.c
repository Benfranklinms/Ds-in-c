#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char item){
    if(top == MAX - 1){
        printf("Stack overflow !!");
    }
    else{
        top++;
        stack[top] = item;
    }
}

char pop(){
    if(top == -1){
        printf("Stack underflow !!");
        return -1;
    }
    else{
        char item = stack[top];
        top--;
        return item;
    }
}

int precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '^'){
        return 3;
    }
    else{
        return 0;
    }
}

void infixToPostfix(char infix[]){
    char item;
    int i = 0;

    while(infix[i] != '\0'){
        if(isalnum(infix[i])){
            printf("%c", infix[i]);
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(item = pop() != '('){
                printf("%c", item);
                if(item != -1){
                    printf("%c", item);
                }
            }
        }
        else{
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])){
                printf("%c", pop());
            }
            push(infix[i]);
        }
        i++;
    }
    while(top != -1){
        printf("%c" ,pop());
    }
    printf("\n");
}

int main(){
    char infix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}