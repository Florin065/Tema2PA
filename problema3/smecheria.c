#include "smecheria.h"

void allocate_arrays() {
    graph = (Vertex *) malloc((n + 1) * sizeof(Vertex));
    dist = (size_t *) malloc((n + 1) * sizeof(size_t));

    for (size_t i = 1; i <= n; i++) {
        graph[i].capacity = 10;
        graph[i].count = 0;
        graph[i].edges = (Edge *) malloc(graph[i].capacity * sizeof(Edge));
        dist[i] = INF;
    }
}

void free_arrays() {
    for (size_t i = 1; i <= n; i++) {
        free(graph[i].edges);
    }
    free(graph);
    free(dist);
}

void add_edge(size_t u, size_t v, size_t w) {
    if (w <= MAX_COST) {
        if (graph[u].count >= graph[u].capacity) {
            graph[u].capacity *= 2;
            graph[u].edges = (Edge *) realloc(graph[u].edges, graph[u].capacity * sizeof(Edge));
        }

        graph[u].edges[graph[u].count].vertex = v;
        graph[u].edges[graph[u].count].weight = w;
        graph[u].count++;
    }
}

void dijkstra(size_t source) {
    size_t *visited = (size_t *) calloc(n + 1, sizeof(size_t));
    dist[source] = 0;

    for (size_t i = 1; i <= n; i++) {
        size_t minDist = INF;
        size_t u = -1;

        for (size_t j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == (size_t) -1)
            break;

        visited[u] = 1;

        for (size_t j = 0; j < graph[u].count; j++) {
            size_t v = graph[u].edges[j].vertex;
            size_t weight = graph[u].edges[j].weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    free(visited);
}