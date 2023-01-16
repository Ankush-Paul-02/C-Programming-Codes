#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

char stack[100];
int top = -1;

void push(char ch) {
    if(top >= 100 ) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    char ele = ' ';
    if(top < 0) {
        printf("Stack Underflow!\n");
    } else {
        ele = stack[top];
        top--;
    }
    return ele;
}

int isOperator(char ch) {
    if(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

int precedence(char ch) {
    if(ch == '^') {
        return 3;
    } else if(ch == '*' || ch == '/') {
        return 2;
    } else if(ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char ch, x;
    push('(');
    strcat(infix, ")");
    i = 0, j = 0;
    
    ch = infix[0];
    while (ch !='\0') {
        if(ch == '(') {
            push(ch);
        } else if(isdigit(ch) || isalpha(ch)) {
            postfix[j] = ch;
            j++;
        } else if(isOperator(ch) == 1) {
            x = pop();
            while(isOperator(ch) == 1 && precedence(x) >= precedence(ch)) {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(ch);
        } else if(ch == ')') {
            x = pop();
            while(x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        } else {
            printf("Invalid expression!\n");
            exit(1);
        }
        i++;
        ch = infix[i];
    }
    if(top > 0) {
        printf("Invalid infix expression!");
        getchar();
        exit(1);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter the infix expression: ");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression is: ");
    puts(postfix);
    return 0;
}
