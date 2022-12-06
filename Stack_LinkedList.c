#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * top = 0;

void push(int data) {
    struct Node * newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;

    top = newNode;
}

void display() {
    struct Node * temp = top;
    if (top == NULL) {
        printf("Stack is empty");
    } else {
        while (temp != 0) {
            printf("%d\t", temp->data);
            printf("\n");
            temp = temp->next;
        }
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void pop() {
    struct Node * temp = top;
    if (top == NULL) {
        printf("Stack is empty");
    } else {
        printf("Pop element is %d\n", top->data);
        top = top->next;
        free(temp);
    }
} 


int main() {

    push(1);
    push(2);
    push(3);
    push(4);
    display(top);
    pop();
    display(top);
    
    return 0;
}
