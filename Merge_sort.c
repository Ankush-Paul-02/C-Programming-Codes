#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int b[left + right];

    while(i <= mid && j <= right) {
        if(arr[i] < arr[j]) {
            b[k] = arr[i];
            i++;
        }
        else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid) {
        while(j <= right) {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    else {
        while(i <= mid) {
            b[k] = arr[i];
            k++;
            i++;
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
    
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
