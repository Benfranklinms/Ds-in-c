#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int stack[MAX];

int top = -1;

void push(int item) {
    if(top == MAX -1) {
        printf("Stack overflow");
    }
    else {
        top++;
        stack[top] = item;
    }
}

int pop() {
    int item;
    if(top == -1) {
        printf("Stack underflow");
        return -1;
    }
    else {
        item = stack[top];
        top--;
        return item;
    }
}

int evaluate(char expression[]) {
    int i = 0;
    int num;
    int result;
    while(expression[i] != '\0') {
        if(expression[i] >= '0' && expression[i] <= '9') {
            num = expression[i] - '0';
            push(num);
        }
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
            int num1, num2, result;

            num2 = pop();
            num1 = pop();
            switch(expression[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
            }
            push(result);
        }
        i++;
    }
    result = pop();
    return result;
}

int main() {
    int num1, num2;
    char expression[MAX];
    printf("Enter the expression : ");
    scanf("%s", expression);
    int result = evaluate(expression);
    printf("%d", result);
}
