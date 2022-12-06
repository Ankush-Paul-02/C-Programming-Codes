#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void countNodes(struct Node *head)   // COUNT TOTAL NUMBER OF NODES OF THE LINKED LIST
{
    int count = 0;
    if (head == NULL)
    {
        printf("Empty list");
    }
    struct Node * ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d\n", count);
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

void add_at_end(struct Node * head, int data) {  // ADD A DATA AT THE END OF THE LINKED LIST
    struct Node *ptr, *new;
    ptr = head;
    new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data; // update the data and the link part of the new node
    new->next = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new;
}

struct Node * add_at_first(struct Node * head, int data) // ADD A DATA AT THE FIRST OF THE LINKED LIST
{
    struct Node * new;
    new = (struct Node *)malloc(sizeof(struct Node));
    
    new->data = data;
    new->next = NULL;

    new->next = head;
    head = new;
    return head;
}

void add_at_position(struct Node * head, int data, int pos)
{
    struct Node * ptr = head;
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;

    pos--;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    new->next = ptr->next;
    ptr->next = new;
}

struct Node * del_first(struct Node * head)
{
    if (head == NULL)
    {
        printf("Empty List!");
    }
    else
    {
        struct Node * ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
    }
    return head;
}

void del_last(struct Node * head)
{
    if (head == NULL)
    {
        printf("Empty list!");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node * ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        
        free(ptr->next);
        ptr->next = NULL;
    }
}

void del_at_pos(struct Node * head, int pos)
{
    struct Node * curr = head;
    struct Node * pre = head;
    if (head == NULL)
    {
        printf("Empty List!");
    }
    else if (pos == 1)
    {
        head = curr->next;
        free(curr);
        curr = NULL;
    }
    else
    {
        while (pos != 1)
        {
            pre = curr;
            curr = curr->next;
            pos--;
        }
        pre->next = curr->next;
        free(curr);
        curr = NULL;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 90;
    head->next = second;

    second->data = 100;
    second->next = third;

    third->data = 200;
    third->next = NULL;

    // del_at_pos(head, 2);
    printData(head);

    return 0;
}