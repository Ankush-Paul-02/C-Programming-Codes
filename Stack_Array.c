#include<stdio.h>
#include<stdlib.h>

int stack[10];
int top = -1;

void push(int data) {
    if(top >= 10) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = data;
        printf("%d is push in the stack.", stack[top]);
    }
}

int pop() {
    int temp = 0;
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        temp = stack[top];
        top--;
    }
    return temp;
}

void peek() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("peek element is %d\n", stack[top]);
    }
}

void display() {
    for(int i = top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
    printf("\t");
}

int main() {
    int choice, data;
    while (1) {
        printf("1.PUSH \n2.POP \n3.PEEK \n4.DISPLAY \n5.EXIT\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf("%d is popped out.\n", pop());
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                break;
        }
    }
    return 0;
}