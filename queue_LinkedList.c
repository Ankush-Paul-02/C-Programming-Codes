#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} s;

s * front = 0;
s * rear = 0;

void enqueue(int x) {
    s * newNode;
    newNode = (s*)malloc(sizeof(s*));
    newNode->data = x;
    newNode->next = NULL;
    if (front == 0 && rear == 0) {
        front = rear = newNode;
        printf("Inserted element is: %d\n", rear->data);
    }
    else {
        rear->next = newNode;
        rear = newNode;
        printf("Inserted element is: %d\n", rear->data);
    }
}

void display() {
    s * temp = front;
    if (front == 0 && rear == 0) {
        printf("Queue is Empty");
    }
    else {
        while(temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void dequeue() {
    s * temp = front;
    if (front == 0 && rear == 0) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Deleted element is: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}

void peek() {
    if (front == 0 && rear == 0) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Front element is: %d\n", front->data);
    }
}

int main() {
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    dequeue();
    display();

    dequeue();
    display();

    peek();

    return 0;
}
