#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define vertices 8

int minimum_distance(int visited[], int distance[]) {
    int min = INT_MAX, min_index;
    for(int i = 0; i < vertices; i++) {
        if(!visited[i] && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int graph[], int x) {
    if(graph[x] == -1) {
        printf("%d ", x);
        return;
    }
    printPath(graph, graph[x]);
    printf("%d ", x);
}

void shortestPath(int source, int distance[], int graph[]) {
    printf("Vertex\tDistance\tPath:\n");
    for(int i = 0; i < vertices; i++) {
        printf("%d\t%d\t\t", i, distance[i]);
        printPath(graph, i);
        printf("\n");
    }
}

void graph_dijkstra_algo(int graph[vertices][vertices], int source) {
    int distance[vertices], visited[vertices], parent[vertices];

    for(int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    distance[source] = 0;

    for(int i = 0; i < vertices-1; i++) {
        int u = minimum_distance(distance, visited);
        visited[u] = 1;
        for(int j = 0; j < vertices; j++) {
            if(visited[i] && graph[u][j] && distance[u] != INT_MAX && distance[u] + graph[u][j] < distance[j]) {
                distance[j] = distance[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
    shortestPath(source, distance, parent);
}

int main() {
    int graph[vertices][vertices];
    srand(time(NULL));
    printf("Random Graph: \n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                int r = rand() % 10;
                if(r == 0) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = r;
                }
                graph[j][i] = graph[i][j];
            }
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    clock_t begin = clock();
    graph_dijkstra_algo(graph, 0);
    clock_t end = clock();

    double time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time: %lf", time);
    return 0;
}