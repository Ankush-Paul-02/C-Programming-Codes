#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "random.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

int max_rec(int arr[], int n) {
    if(n == 1) return arr[0];
    
    return max(arr[n-1], max_rec(arr, n-1));
}

int min_rec(int arr[], int n) {
    if(n == 1) return arr[0];
    
    return min(arr[n-1], min_rec(arr, n-1));
}

int main() {
    long n = 5;
    int *arr;
    arr = newHeader();

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    clock_t start = clock();
    int min = min_rec(arr, n);
    int max = max_rec(arr, n);
    clock_t end = clock();

    double time = (end-start)/CLOCKS_PER_SEC;
    
    printf("Min element: %d\n", min);    
    printf("Max element: %d\n", max);

    printf("Time taken for this: %lf", time);

    return 0;
}



