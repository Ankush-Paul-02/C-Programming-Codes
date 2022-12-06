#include<stdio.h>

char stack[100];
int top = -1;

void push(char ch) {
    if(top > 100) {
        printf("Overflow");
    }
    else {
        top++;
        stack[top] = ch;
    }
}

int pop() {
    int temp = ' ';
    if(top < 0) {
        printf("Underflow");
    }
    else {
        temp = stack[top];
        top--;
    }
    return temp;
}

int main() {
    
    char str[100];
    printf("Enter your parenthesis: ");
    gets(str);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(') {
            push(str[i]);
        }
        else if(str[i] == ')') {
            if(top == -1) {
                printf("Mismatch");
                return 0;
            }
            pop();
        }
    }
    if(top >= 0) {
        printf("Mismatch");
    }
    else {
        printf("match");
    }

    return 0;
}