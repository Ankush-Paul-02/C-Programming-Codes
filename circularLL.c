#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node * next, * prev;
} s;

s * head = NULL;

void display() {
    s * temp;
    if(head == NULL) {
        printf("List is empty!");
    }
    else {
        temp = head;
        while(temp->next != head) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
    
}

void addAtFirst() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    s * temp;
    s * newNode;
    newNode = (s *)malloc(sizeof(s));
    newNode->data = data;

    if(head == NULL) {
        head = newNode;
        newNode->next = newNode->prev =  newNode;
    }
    else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        } 
        newNode->next = temp->next;
        newNode->prev = head->prev;
        head->prev = newNode;
        temp->next = newNode;
        head = newNode;
    }
}

void addAtLast() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    s * temp = head;
    s * newNode;
    newNode =(s *)malloc(sizeof(s));
    newNode->data = data;

    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    head->prev = newNode;
    newNode->next = head;

}

void deletevalue() {
	int value;
	printf("Enter the value which you want to delete: ");
	scanf("%d", &value);

	s * ptr = head;
	s * temp;
	
	while(ptr->next != head) {
		if(ptr->next->data == value) {
			temp = ptr->next;
			ptr->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
		}
		ptr = ptr->next;
	}
    
}

void deleteFirst() {
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = head->next;
}

void deleteLast() {
    s * temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    head->prev = temp->prev;
    free(temp);
}

int main() {

    int choice;

    while(choice) {
        printf("\n1. Add first 2. Add last 3. Delete First 4. Delete last 5. display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAtFirst();
                break;
            case 2:
                addAtLast();
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5: 
                deletevalue();
                break;
            case 6:
                display();
                break;
        }
    }
    return 0;
}
