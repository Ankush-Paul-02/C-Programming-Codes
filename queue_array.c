#include<stdio.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

void enqueue (int element) 
{   
    if (rear == size -1)
    {
        printf("Overflow condition\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = element;
        printf("Inserted element is: %d\n", queue[rear]);
    }
    else
    {
        rear++;
        queue[rear] = element;
        printf("Inserted element is: %d\n", queue[rear]);
    }
}

void dequeue ()
{
    if (front == -1 && rear == -1)
    {
        printf("UnderFlow condition");
    }
    else if (front == rear) 
    {
        printf("Deleted element is: %d\n", queue[front]);
        front = rear = -1;
    }
    else 
    {
        printf("Deleted element is: %d\n", queue[front]);
        front++;
    }
}

void display() 
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        for(int i = front; i < rear + 1; i++) {
            printf("%d\t", queue[i]);
            printf("\n");
        }
    }
}

void peek() {
    if (front == -1 && rear == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        printf("Data at front is:  %d", queue[front]);
    }
    
}

int main() 
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    dequeue();
    display();

    dequeue();
    display();

    peek();

    return 0;
}
