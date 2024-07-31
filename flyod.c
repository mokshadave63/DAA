#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 5

// Define infinity as the maximum value of int plus one
#define INF INT_MAX

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    // Before start of an iteration, we have shortest distances between all pairs of vertices such that the shortest
    // distances consider only the vertices in the set {0, 1, 2, .. k-1} as intermediate vertices.
    // After the end of an iteration, vertex no. k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k}
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

// A utility function to print the solution matrix
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph representation
    int graph[V][V] = {
        {0, -1, 4, INF, INF},
        {INF, 0, 3, 2, 2},
        {INF, INF, 0, INF, INF},
        {INF, 1, 5, 0, INF},
        {INF, INF, INF, -3, 0}
    };

    // Print the solution
    floydWarshall(graph);
    return 0;
}
