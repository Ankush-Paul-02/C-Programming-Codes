#include<stdio.h>
#include<stdlib.h>

#define size 25
int queue[size];
int front = -1, rear = -1;
int capacity = 0;

void insert() {
    int element;
    printf("Enter the element: ");
    scanf("%d", &element);
    if(capacity < size) {
        rear = (rear+1)%size;
        queue[rear] = element;
        capacity++;
    }
    else {
        printf("Overflow condition.");
    }
}

void delete() {
    if(capacity > 0) {
        front = (front+1)%size;
        printf("Deleted Element is: %d", queue[front]);
        capacity--;
    }
    else {
        printf("Underflow condition.");
    }
}

void display() {
    int j = capacity;
    for(int  i = front+1; j >= 1; j--, i = (i+1)%capacity) {
        printf("%d\t", queue[i]);
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Insert\n2. Delete\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }
    return 0;
}