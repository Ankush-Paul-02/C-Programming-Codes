#include<stdlib.h>
#include<time.h>

int n = 5;
int * newHeader() {
    int * a, limit = 10;
    a = (int *)malloc(n * 4);
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        a[i] = rand() % limit;
    }
    return a;
}