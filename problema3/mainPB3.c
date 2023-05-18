#include "smecheria.h"

Vertex *graph;
size_t *dist;
size_t n;

int main() {
    FILE *in = fopen("date.in", "r");
    size_t m, source, u, v, w;
    fscanf(in, "%zu %zu %zu", &n, &m, &source);

    allocate_arrays();

    for (size_t i = 0; i < m; i++) {
        fscanf(in, "%zu %zu %zu", &u, &v, &w);
        add_edge(u, v, w);
    }
    fclose(in);

    dijkstra(source);

    FILE *out = fopen("date.out", "w");
    for (size_t i = 1; i <= n; i++) {
        if (i == source) {
            fprintf(out, "0 ");
        } else if (dist[i] != INF) {
            fprintf(out, "%zu ", dist[i]);
        } else {
            fprintf(out, "-1 ");
        }
    }
    fprintf(out, "\n");
    fclose(out);

    free_arrays();

    return 0;
}