#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} s;

s * head;

void printData(struct Node * head) {
    if (head == NULL) {
        printf("Empty list");
    }
    struct Node * ptr = NULL;
    ptr = head;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

s * bubble_sort(s * head) {
    int flag = 0;
    int count = 0;
    s * temp = head;
    while(temp != NULL) {
        count++;
    }
    
    for(int i = 0; i < count - 1; i++) {
        temp = head;
        flag = 0;
        for(int j = 0; j < count - i - 1; j++) {
            s * ptr1 = temp;
            s * ptr2 = temp->next;
            if(ptr1->data > ptr2->data) {
                int swap = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = swap;
                flag = 1;
            }
            temp = temp->next;
        }
        if(flag == 0) {
            break;
        }
    }
    return head;
}

int main() {

    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head = first;

    first->data = 50;
    first->next = second;

    second->data = 40;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = fifth;

    fifth->data = 10;
    fifth->next = NULL;

    printData(head);
    head = bubble_sort(head);
    printData(head);
    
    
    return 0;
}
