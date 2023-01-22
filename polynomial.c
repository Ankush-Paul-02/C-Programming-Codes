#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial {
    int coefficient, power;
    struct polynomial * next;
} p;

p * head1 = NULL, * head2 = NULL, * temp1, * temp2, * res;
int choice;

void create_expression(int x, int y, p ** temp) { 
    p *r, *z; 
    z = *temp; 
    if (z == NULL) { 
        r = (p*)malloc(sizeof(p)); 
        r->coefficient = x; 
        r->power = y; 
        *temp = r; 
        r->next = (p*)malloc(sizeof(p)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else { 
        r->coefficient = x; 
        r->power = y; 
        r->next = (p*)malloc(sizeof(p)); 
        r = r->next; 
        r->next = NULL; 
    }
} 

void display(p * head) {
    p * temp = head;
    printf("polynomial: ");
    while(temp->next != NULL) {
        printf("%dx^%d", temp->coefficient, temp->power);
        temp = temp->next;
        if(temp->coefficient >= 0) {
            if(temp->next != NULL) {
                printf(" + ");
            }
        }
    }
}

void add(p * head1, p * head2, p * res) {
    temp1 = head1, temp2 = head2;
    while(temp1->next != NULL && temp2->next != NULL) {
        if(temp1->power == temp2->power) {
            res->power = temp1->power;
            res->coefficient = temp1->coefficient + temp2->coefficient;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if(temp1->power > temp2->power) {
            res->power = temp1->power;
            res->coefficient = temp1->coefficient;
            temp1 = temp1->next;
        } else {
            res->power = temp2->power;
            res->coefficient = temp2->coefficient;
            temp1 = temp2->next;
        }
        res->next = (p*)malloc(sizeof(p));
        res = res->next;
        res->next = NULL;
    }
    while (temp1->next || temp2->next) {
        if(temp1->next) {
            res->power = temp1->power;
            res->coefficient = temp1->coefficient;
            temp1 = temp1->next;
        }
        if(temp2->next) {
            res->power = temp2->power;
            res->coefficient = temp2->coefficient;
            temp1 = temp2->next;
        }
        res->next = (p*)malloc(sizeof(p));
        res = res->next;
        res->next = NULL;
    }
}

int main() {

    create_expression(5, 2, &head1);
    create_expression(4, 1, &head1);
    create_expression(2, 0, &head1);

    printf("1st polynomial is: ");
    display(head1);
    printf("\n");

    create_expression(-5, 1, &head2);
    create_expression(-5, 0, &head2);

    printf("2nd polynomial is: ");
    display(head2);
    printf("\n");

    res = (p*)malloc(sizeof(p)); 
    add(head1, head2, res);
    printf("Resultant expression: ");
    display(res);

    return 0;
}