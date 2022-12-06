#include <stdio.h>

int stack[10]; // globally declared // 0, 1 ,2, 3, 4, 5, 6, 7, 8, 9
int top = -1;

void push(int n) { // put a number in stack
    if (top >= 10) {
       printf("full"); 
    } else {
        top++; // top = 1
        stack[top] = n;
        printf("%d element is pushed in the stack!!\n", stack[top]);
    }
}

int pop() { // remove and display a number from stack
    int temp = 0;
    if (top == -1) {
        printf("Under flow condition!!\n");
    } else {
        temp = stack[top];
        top--;
    }
    return temp;
}

void peek() { // just see the top most number of the stack
    if (top < 0) {
        printf("Empty stack!!");
    } else {
        printf("%d number is in peek!!\n", stack[top]);
    }
}

void display() { // display the stack
    for (int i = top; i >= 0; i--) {
        printf("Stack is : %d\t", stack[i]);
    }
    printf("\n");
}

int main() {   
    int ans = 0;
    int num = 0;
    while (1) {
        printf("1.PUSH \n2.Pop \n3.Peek \n4.display \n5.exit\n");
        printf("Choose your option : ");
        scanf("%d", &ans);
        if (ans == 1) {
            printf("Enter a number to push : ");
            scanf("%d", &num);
            push(num);
        } else if (ans == 2) {
            num = pop();
            printf("%d is poped up!!\n", num);
        } else if (ans == 3) {
            peek();
        } else if (ans == 4) {
            display();
        } else {
            break;
        }   
    }
    return 0;
}
