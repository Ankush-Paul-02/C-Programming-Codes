#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "random.h"


void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void heapify(int arr[], int index, int n) {
    int left = 2*index+1;
    int right = 2*index+2;

    int maxIndex = index;

    if(left < n && arr[left] > arr[maxIndex]) {
        maxIndex = left;
    }

    if(right < n && arr[right] > arr[maxIndex]) {
        maxIndex = right;
    }

    if(maxIndex != index) {
        swap(arr, index, maxIndex);
        heapify(arr, maxIndex, n);
    }

}

void heapSort(int arr[], int n) {
    for(int i = n/2; i >= 0; i--) {
        heapify(arr, i, n);
    }

    for(int i = n-1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, 0, i);
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
    heapSort(arr, n);
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