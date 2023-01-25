#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} q;

q *front = 0, *rear = 0;

void enQueue(int data) {
    q *newNode = (q*)malloc(sizeof(q));
    newNode->data = data;   
    newNode->next = NULL;

    if(front == 0 && rear == 0) {
        front = rear = newNode;
        printf("Inserted data is: %d\n", rear->data);
    } else {
        rear->next = newNode;
        rear = newNode;
        printf("Inserted data is: %d\n", rear->data);
    }
}

void deQueue() {
    q *temp = front;
    if(front == 0 && rear == 0) {
        printf("Underflow condition!\n");
    } else {
        printf("Deleted data is: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    q *temp = front;
    if(front == 0 && rear == 0) {
        printf("Underflow condition!\n");
    } else {
        while(temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
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