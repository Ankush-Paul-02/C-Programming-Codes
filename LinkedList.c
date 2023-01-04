#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} s;

s * head = NULL;

void printLinkedList(s *head) {
    if(head == NULL) {
        printf("Empty LinkedList!");
    }
    s *temp = head;
    while(temp != NULL) {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

s * addFirst(int data) {
    s * newNode = (s*)malloc(sizeof(s));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return head;
    }

    newNode->next = head;
    head = newNode;
    return head;
}

s * addLast(int data) {
    s * newNode = (s*)malloc(sizeof(s));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return head;
    }

    s *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

s * deleteFirst(s * head) {
    if(head == NULL) {
        return NULL;
    }
    printf("Deleted value is: %d\n", head->data);
    head = head->next;
    return head;
}

s * deleteLast(s * head) {
    if(head == NULL) {
        return NULL;
    } else if(head->next == NULL) {
        printf("Deleted value is: %d\n", head->data);
        free(head);
        head = NULL;
        return NULL;
    }
    s * temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted value is: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

s * addAtMiddle(s * head, int data) {
    if(head == NULL) {
        head = addFirst(data);
        return head;
    }
    int val;
    printf("Enter the value after which you want to insert: ");
    scanf("%d", &val);
    s * prev = head;
    s * newNode;
    newNode = (s*)malloc(sizeof(s));
    newNode->data = data;
    newNode->next = NULL;

    while(prev->data != val) {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    return head;
}

s * deleteAtMiddle(s * head, int data) {
    s * prev = head, * next;
    while(prev->next->data != data) {
        prev = prev->next;
    }
    next = prev->next->next;
    printf("Deleted value is: %d\n", prev->next->data);
    free(prev->next);
    prev->next = next;
    return head;
}

int main() {

    while(1) {
        int option, data;
        printf("1. Insert First\n2. Insert Last\n3. Delete First\n4. Delete Last\n5. Insert Middle\n6. Delete Middle\n7. Print\n8. Exit.\n");
        printf("Enter your option : ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            head = addFirst(data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            head = addLast(data);
            break;
        case 3:
            head = deleteFirst(head);
            break;
        case 4: 
            head = deleteLast(head);
            break;
        case 5:
            printf("Enter the data: ");
            scanf("%d", &data);
            head = addAtMiddle(head, data);
            break;
        case 6:
            printf("Enter the data which you want to delete: ");
            scanf("%d", &data);
            head = deleteAtMiddle(head, data);
            break;
        case 7:
            printLinkedList(head);
            printf("\n");
            break;
        case 8:
            exit(1);
        default:
            break;
        }
    }
    return 0;
}