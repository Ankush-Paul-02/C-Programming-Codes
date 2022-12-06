#include<stdio.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
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

    printf("Array before sorting:\t");
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    insertion_sort(arr, n);

    printf("\n");
    printf("Array after sorting:\t");
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}