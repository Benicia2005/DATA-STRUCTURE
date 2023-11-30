#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Graph {
    int** adjacencyList;
    int vertices;
};

// Function to initialize a graph
struct Graph* initializeGraph(int vertices, int edges[][2], int edgesSize) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            graph->adjacencyList[i][j] = 0;
        }
    }

    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph->adjacencyList[u][v] = 1;
        graph->adjacencyList[v][u] = 1;
    }

    return graph;
}

// Depth-First Search
bool dfs(struct Graph* graph, int current, int destination, int* visited) {
    if (current == destination) {
        return true;
    }

    visited[current] = 1;

    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->adjacencyList[current][i] && !visited[i]) {
            if (dfs(graph, i, destination, visited)) {
                return true;
            }
        }
    }

    return false;
}

// Function to check if there is a valid path from source to destination
bool validPath(struct Graph* graph, int source, int destination) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    bool result = dfs(graph, source, destination, visited);

    free(visited);
    return result;
}

int main() {
    // Example 1
    int n1 = 3;
    int edges1[][2] = {{0, 1}, {1, 2}, {2, 0}};
    int source1 = 0;
    int destination1 = 2;

    struct Graph* graph1 = initializeGraph(n1, edges1, sizeof(edges1) / sizeof(edges1[0]));

    bool result1 = validPath(graph1, source1, destination1);
    printf("Output 1: %s\n", result1 ? "true" : "false");

    // Example 2
    int n2 = 6;
    int edges2[][2] = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source2 = 0;
    int destination2 = 5;

    struct Graph* graph2 = initializeGraph(n2, edges2, sizeof(edges2) / sizeof(edges2[0]));

    bool result2 = validPath(graph2, source2, destination2);
    printf("Output 2: %s\n", result2 ? "true" : "false");

    // Free allocated memory
    for (int i = 0; i < n1; ++i) {
        free(graph1->adjacencyList[i]);
    }
    free(graph1->adjacencyList);
    free(graph1);

    for (int i = 0; i < n2; ++i) {
        free(graph2->adjacencyList[i]);
    }
    free(graph2->adjacencyList);
    free(graph2);

    return 0;
}
