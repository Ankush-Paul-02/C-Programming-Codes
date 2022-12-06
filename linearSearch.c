#include<stdio.h>

int main() {

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter element at index %d : ", i);
        scanf("%d", &arr[i]);
    }

    int ele, flag = 0;
    printf("Enter the element which you want to search: ");
    scanf("%d", &ele);

    for(int i = 0; i < n; i++) {
        if(arr[i] == ele) {
            flag = 1;
        }
    }

    if(flag == 1) {
        printf("The element is present");
    }
    else {
        printf("The element is absent");
    }

    return 0;
}