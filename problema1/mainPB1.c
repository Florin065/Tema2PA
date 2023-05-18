#include "cycleDetection.h"

int main() {
    FILE *in = fopen("date.in", "r");
    FILE *out = fopen("date.out", "w");

    size_t N, M, u, v;
    fscanf(in, "%zu %zu", &N, &M);

    // Initialize the graph
    graph G;
    init_graph(&G);

    // Read edges from the file and add them to the graph
    for (size_t i = 0; i < M; i++) {
        fscanf(in, "%zu %zu", &u, &v);
        add_edge(&G, u, v);
    }


    // Check if the graph contains a cycle
    bool hasCycle = is_cyclic(&G, N);

    if (hasCycle) {
        fprintf(out, "are ciclu\n");
    } else {
        fprintf(out, "nu are ciclu\n");
    }

    fclose(in);
    fclose(out);

    return 0;
}
