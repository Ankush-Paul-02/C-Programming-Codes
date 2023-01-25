#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

void enQueue(int data) {
    if(front == size-1) {
        printf("Overflow!\n");
    } else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
        printf("Inserted data is: %d\n", queue[rear]);
    } else {
        rear++;
        queue[rear] = data;
        printf("Inserted data is: %d\n", queue[rear]);
    }
}

void deQueue() {
    if(front == -1 && rear == -1) {
        printf("Underflow condition!\n");
    } else if(front == rear) {
        printf("Deleted data is: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted data is: %d\n", queue[front]);    
        front++;
    }
}

void display() {
    if(front == -1 && rear == -1) {
        printf("Underflow condition!\n");
    } else {
        for (int i = front; i < rear+1; i++) {
            printf("%d\t", queue[i]);       
        }
        printf("\n");
    }
}

int main() {
    while(1) {
        int option, data;
        printf("1. EnQueue\n2. DeQueue\n3. Display\n4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            enQueue(data);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}