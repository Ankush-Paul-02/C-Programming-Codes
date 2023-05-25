#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define V 6 


int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[]) {
    printf("Shortest distances from the source vertex:\n");
    for (int i = 0; i < V; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     
    int visited[V];  
    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;


    for (int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    
    int graph[V][V] = {{0, 2, 0, 0, 0, 0},
                       {2, 0, 3, 0, 0, 0},
                       {0, 3, 0, 4, 0, 0},
                       {0, 0, 4, 0, 5, 0},
                       {0, 0, 0, 5, 0, 6},
                       {0, 0, 0, 0, 6, 0}};

    int src = 0;
    clock_t start = clock();
    dijkstra(graph, src);
    clock_t end = clock();

    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time: %lf", time);
    return 0;
}
