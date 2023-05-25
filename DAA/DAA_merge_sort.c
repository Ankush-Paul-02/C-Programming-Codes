#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "random.h"

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int b[left + right];

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            b[k++] = arr[i++];
        }
        else {
            b[k++] = arr[j++];
        }
    }
    if(i > mid) {
        while(j <= right) {
            b[k++] = arr[j++];
        }
    }
    else {
        while(i <= mid) {
            b[k++] = arr[i++];
        }    
    }

    for(k = left; k <= right; k++) {
        arr[k] = b[k];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n-1);
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