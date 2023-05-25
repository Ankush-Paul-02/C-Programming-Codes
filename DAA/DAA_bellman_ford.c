#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Edge {
    int source, destination, weight;
} edge;

typedef struct Graph {
    int vertices, edges;
    edge *edge;
} graph;


graph* createGraph(int vertices) {
    graph *g = (graph*)malloc(sizeof(graph)); 
    g->vertices = vertices;
    g->edges = 5;

    g->edge = (edge*)malloc(g->edges * (sizeof(edge)));

    g->edge[0].source = 0;  //? 0->1
    g->edge[0].destination = 1;
    g->edge[0].weight = 2;

    g->edge[1].source = 0;  //? 0->2
    g->edge[1].destination = 2;
    g->edge[1].weight = 4;

    g->edge[2].source = 1;  //? 1->2
    g->edge[2].destination = 2;
    g->edge[2].weight = -4;

    g->edge[3].source = 2;  //? 2->3
    g->edge[3].destination = 3;
    g->edge[3].weight = 2;

    g->edge[4].source = 3;  //? 3->4
    g->edge[4].destination = 4;
    g->edge[4].weight = 4;

    g->edge[5].source = 4;  //? 4->1
    g->edge[5].source = 1;
    g->edge[5].source = -1;

    return g;
}

void printGraph(int distance[], int vertices) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; ++i) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}


void BellmanFord(struct Graph* graph, int source) {
    int V = graph->vertices;
    int E = graph->edges;
    int distance[V];
  

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
  

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }
    }  
    printGraph(distance, V);
}

int main() {

    int vertices = 5;
    graph * g = createGraph(vertices);
    BellmanFord(g, 0);    
    return 0;
}