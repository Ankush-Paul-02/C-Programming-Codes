#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

struct Node * head;

struct Node * reverese(struct Node * head) {
	struct Node * curr, * pre, * next;
	curr = head;
	pre = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}
	head = pre;
	return head;
}

void printData(struct Node * head) // PRINT OUT THE LINKED LIST
{
    if (head == NULL)
    {
        printf("Empty list");
    }
    struct Node * ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * middle(struct Node * head) {
    struct Node * slow = head;
    struct Node * fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int isPalindrome(struct Node * head) {
    if(head == NULL) {
        return 1;
    }
    struct Node * mid = middle(head);
    struct Node * last = reverese(mid->next);
    struct Node * curr = head;
    while(last != NULL) {
        if(last->data != curr->data) {
            return 0;
        }
        last = last->next;
        curr = curr->next;
    }
    return 1;
}

int main() {

	struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

	struct Node * head = first;

    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 0;
    third->next = fourth;
	fourth->data = 20;
    fourth->next = fifth;
	fifth->data = 10;
    fifth->next = NULL;

	// printData(head);
	// head = reverese(head);   // for reverese
	// printData(head);

    if(isPalindrome(head)) {
        printf("Palindrome");
    } else {
        printf("Not Palindrome");
    }
	
	return 0;
}
