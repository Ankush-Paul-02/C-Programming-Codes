#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#define vertices 4
#define INF 99999

void printGraph(int graph[][vertices]) {
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            if(graph[i][j] == INF) {
                printf("%4s", "INF");
            } else {
                printf("%4d", graph[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][vertices]) {
    int newGraph[vertices][vertices];

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            newGraph[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < vertices; k++) {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                if(newGraph[i][k] + newGraph[k][j] < newGraph[i][j]) {
                    newGraph[i][j] = newGraph[i][k] + newGraph[k][j];
                }
            }
        }
    }
    printGraph(newGraph);
}

int main() {
    int graph[vertices][vertices] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0},
    };

    clock_t start = clock();
    floydWarshall(graph);
    clock_t end = clock();

    double time = (end-start)/CLOCKS_PER_SEC;
    printf("Time taken to find the shortest path: %lf", time);

    return 0;
}