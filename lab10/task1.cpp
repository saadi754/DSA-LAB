#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices

// Helper function to find the vertex with minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];    // Holds the shortest distance from src to i
    bool sptSet[V]; // True if vertex is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i]   = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0; // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Pick minimum distance vertex
        sptSet[u] = true;                  // Mark as processed

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            // Update dist[v] only if it's not in sptSet, there is an edge,
            // and total weight of path from src to v is smaller than current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDistance from Source (0)\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main() {
    // Weighted Adjacency Matrix representation
    int graph[V][V] = {
        {0, 10,  0, 0, 5},
        {10,  0,  1, 0, 2},
        {0,  1,  0, 4, 0},
        {0,  0,  4, 0, 3},
        {5,  2,  0, 3, 0}
    };

    dijkstra(graph, 0); // Find shortest paths starting from vertex 0

    return 0;
}