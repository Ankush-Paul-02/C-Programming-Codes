#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *prev, *next;
} s;

s * head = NULL;

void traverse(){
	
	if (head == NULL) {
		printf("\nList is empty\n");
		return;
	}
	s * temp;
	temp = head;
	while (temp != NULL) {
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}

void insertAtFront() {
    int data;
    s * new;
    new = (s *)malloc(sizeof(s));
    printf("Enter number to be inserted: ");
    scanf("%d", &data);
    new->data = data;
    new->prev = NULL;

    new->next = head;
    head = new;
}

void insertAtEnd() {
	int data;
	s * new = (s *)malloc(sizeof(s));;
	printf("Enter number to be inserted: ");
    scanf("%d", &data);
	new->data = data;
	new->next = NULL;

	s * temp;
	temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	new->prev = temp;
	temp->next = new;
}

void insertAtPos() {
	int value, pos, i = 1;
	printf("Enter the data: ");
	scanf("%d", &value);

	s * new = malloc(sizeof(s));
	new->data = value;
	
	printf("Enter the position: ");
	scanf("%d", &pos);
	
	s * temp = head;
	while(i < pos-1) {
		temp = temp->next;
		i++;
	}
	new->next = temp->next;
	new->prev = temp;
	temp->next = new;
	temp->next->prev = new;
}

void deleteFirst() {
	head = head->next;
	head->prev = NULL;
}

void deleteLast() {
	s * temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
}

void deletevalue() {
	int value;
	printf("Enter the value which you want to delete: ");
	scanf("%d", &value);

	s * ptr = head;
	s * temp;
	
	while(ptr->next != NULL) {
		if(ptr->next->data == value) {
			temp = ptr->next;
			ptr->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
		}
		ptr = ptr->next;
	}
}

int main()
{
	int choice, size;
	while (1) {

		printf("\n1. Display list\n2. Create List\n3. Add at first\n4. Add at last\n5. Add at position\n6. Delete first\n7. Delete last\n8. Delete from pos\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtFront();
			break;
		case 4:
			insertAtEnd();
			break;
		case 5:
			insertAtPos();
			break;
		case 6:
			deleteFirst();
			break;
		case 7:
			deleteLast();
			break;
		case 8:
			deletevalue();
			break;
		case 9:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}
