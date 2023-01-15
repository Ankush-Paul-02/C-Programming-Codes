#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} ll;

ll * root = NULL;

void push(int data) {
    ll * newNode = (ll *)malloc(sizeof(ll));
    newNode->data = data;
    newNode->next = root;
    root = newNode;
}

void pop() {
    ll * newNode = root;
    if(root == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("%d element is popped out.\n", root->data);
        root = newNode->next;
        free(newNode);
    }
}

void peek() {
    if(root == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Peeked element is: %d\n", root->data);
    }
}

void display() {
    ll * temp = root;
    if(root == NULL) {
        printf("Stack is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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
                pop();
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