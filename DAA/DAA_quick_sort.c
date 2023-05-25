#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "random.h"


void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], pIndex = low;
    
    for(int i = low; i < high; i++) {
        if(arr[i] < pivot) {
            swap(arr, i, pIndex);
            pIndex++;
        }
    }
    swap(arr, high, pIndex);
    return pIndex;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main() {
    long n = 5;
    int *arr;
    arr = newHeader();

    printf("Array before sorting: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start = clock();
    quickSort(arr, 0, n-1);
    clock_t end = clock();

    printf("Array after sorting: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double time = (end-start)/CLOCKS_PER_SEC;
    printf("Time is taken for this sorting: %lf", time);

    return 0;
}