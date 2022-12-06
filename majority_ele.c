#include<stdio.h>

void majority(int arr[], int n) {
    int ansIndex = 0;
    int count = 1;
    int maxTimes = 0;

    for (int i = 1; i < n; i++) {
        if(arr[i] == arr[ansIndex]) {
            count++;
        }
        else {
            count--;
        }
        if(count == 0) {
            ansIndex = i;
            count = 1;
        }
    }
    // check if ansIndex is actually the answer
    for(int i = 0; i < n; i++) {
        if(arr[ansIndex] == arr[i]) {
            maxTimes++;
        }
    }

    if(maxTimes < n/2) {
        printf("No majority elements");
    } 
    else {
        printf("Majority element is: %d", arr[maxTimes]);
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

    majority(arr, n);

    return 0;
}
