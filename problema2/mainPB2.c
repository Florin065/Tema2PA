#include "distances.h"

size_t n, m, s;
size_t **adj;
size_t *dist;
size_t *visited;
size_t *topo;
size_t topo_size = 0;


int main() {
    FILE *in = fopen("date.in", "r");
    fscanf(in, "%zu %zu %zu", &n, &m, &s);

    // Dynamically allocate memory for adjacency matrix
    adj = (size_t **) malloc((n + 1) * sizeof(size_t *));
    for (size_t i = 0; i <= n; i++) {
        adj[i] = (size_t *) calloc((n + 1), sizeof(size_t));
    }

    dist = (size_t *) malloc((n + 1) * sizeof(size_t));
    visited = (size_t *) calloc((n + 1), sizeof(size_t));
    topo = (size_t *) malloc((n + 1) * sizeof(size_t));

    for (size_t i = 1; i <= m; i++) {
        size_t u, v, w;
        fscanf(in, "%zu %zu %zu", &u, &v, &w);
        adj[u][v] = w;
    }
    fclose(in);

    topological_sort();
    calculate_distances();

    FILE* out = fopen("date.out", "w");
    for (size_t i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            fprintf(out, "-1 ");
        }
        else {
            fprintf(out, "%zu ", dist[i]);
        }
    }
    fprintf(out, "\n");
    fclose(out);

    // Free dynamically allocated memory
    for (size_t i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(dist);
    free(visited);
    free(topo);

    return 0;
}
