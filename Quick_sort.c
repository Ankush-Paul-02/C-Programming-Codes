#include<stdio.h>

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int pIndex = low;
    for(int i = low; i < high; i++) {
        if(arr[i] < pivot) {
            swap(arr, i, pIndex);
            pIndex++;
        }
    }
    swap(arr, high, pIndex);
    return pIndex;
}

void Quick_Sort(int arr[], int low, int high) {

    if(low < high) {
       int pivot = partition(arr, low, high);
       Quick_Sort(arr, low, pivot-1);
       Quick_Sort(arr, pivot+1, high);
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
    

    printf("\n");
    printf("Array after sorting:\t");
    Quick_Sort(arr, 0, n-1);

    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
