#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list for each vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent a graph
struct Graph {
    int vertices;
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
	int i;
    for (i = 0; i < vertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform Depth-First Search traversal
void DFS(struct Graph* graph, int vertex, int visited[]) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Traverse all adjacent vertices
    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to initiate DFS traversal from a given vertex
void DFSTraversal(struct Graph* graph, int startVertex) {
	int i;
    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    for ( i = 0; i < graph->vertices; ++i) {
        visited[i] = 0;
    }

    // Perform DFS traversal starting from the given vertex
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

int main() {
    // Example usage
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Perform DFS traversal starting from vertex 0
    DFSTraversal(graph, 0);

    // Free allocated memory
    free(graph->array);
    free(graph);

    return 0;
}
