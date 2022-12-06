#include<stdio.h>

int binarySearch(int arr[], int low, int high, int element) {

    if(high > low) {
        int mid = low + (high - low)/2;

        if(arr[mid] == element) {
            return mid;
        }
        else if(arr[mid] > element) {
            return binarySearch(arr, low, mid-1, element);
        }
        else if(arr[mid] < element) {
            return binarySearch(arr, mid+1, high, element);
        }
    }
    return -1;
}

int main() {
    
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter element at index %d : ", i);
        scanf("%d", &arr[i]);
    }

    int ele, result;
    printf("Enter the element which you want to search: ");
    scanf("%d", &ele);
    
    result = binarySearch(arr, 0, n-1, ele);

    if(result == -1) {
        printf("The element is absent");
    }
    else {
        printf("The element is present");
    }

    return 0;
}