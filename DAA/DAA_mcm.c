#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>


int mcm_rec(int arr[], int i, int j) {
    if(i == j) {
        return 0;
    }
    int answer = INT_MAX;

    for(int k = i; k <= j-1; k++) {
        int cost1 = mcm_rec(arr, i, k);
        int cost2 = mcm_rec(arr, k+1, j);
        int cost3 = arr[i-1] * arr[k] * arr[j];
        int finalCost = cost1 + cost2 + cost3;
        answer = answer >  finalCost ? finalCost : answer;
    }
    return answer;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int matrix[n];

    printf("Enter elemets for matrix: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &matrix[i]);
    }

    clock_t start = clock();
    printf("%d\n", mcm_rec(matrix, 1, n-1));
    clock_t end = clock();

    double time = (end-start)/CLOCKS_PER_SEC;
    printf("Time is taken: %lf", time);


    return 0;
}