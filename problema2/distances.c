#include "distances.h"

void dfs(size_t u) {
    visited[u] = 1;
    for (size_t v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
    topo[topo_size++] = u;
}

void topological_sort() {
    for (size_t u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    for (size_t i = 0; i < n; i++) {
        dist[topo[i]] = INF;
    }
    dist[s] = 0;
}

void calculate_distances() {
    for (int i = n - 1; i >= 0; i--) {
        size_t u = topo[i];
        for (size_t v = 1; v <= n; v++) {
            if (adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}