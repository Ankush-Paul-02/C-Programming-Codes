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

int binarySearch(int arr[], int low, int high, int element) {
    if(low < high) {
        int mid = low + (high-low)/2;

        if(arr[mid] == element) {
            return mid;
        } else if(arr[mid] > element) {
            return binarySearch(arr, low, mid-1, element);
        } else if(arr[mid] < element) {
            return binarySearch(arr, mid+1, high, element);
        }
    }
    return -1;
}

int main() {
    long n = 5;
    int *arr = newHeader();
    int element, result; 

    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the element you want to search: ");
    scanf("%d", &element);

    clock_t start = clock();
    result = binarySearch(arr, 0, n-1, element);
    clock_t end = clock();

    double time = (end-start)/CLOCKS_PER_SEC;
    printf("The element is located at index: %d\n", result);
    printf("Time taken to search the element is: %lf\n", time);

    return 0;
}