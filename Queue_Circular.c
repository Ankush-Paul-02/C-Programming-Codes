#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size];
int front = -1, rear = -1, capacity = 0;

void enQueue(int data) {
    if(capacity < size) {
        rear = (rear+1)%size;
        queue[rear] = data;
        capacity++;
    } else {
        printf("Overflow!\n");
    }
}

void deQueue() {
    if(capacity > 0) {
        front = (front+1)%size;
        printf("Deleted data is: %d\n", queue[front]);  
        capacity--;
    } else {
        printf("Underflow condition!\n");
    }
}

void display() {
    int cap = capacity;
    for(int i = front+1; cap >= 1; cap--, i = (i+1)%capacity) {
        printf("%d\t", queue[i]);
    }
    printf("\n");
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