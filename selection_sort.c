#include<stdio.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
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

    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            swap(arr, min, i);
        }
    }

    printf("\n");
    printf("Array after sorting:\t");
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
