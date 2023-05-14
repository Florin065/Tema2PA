#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "cycleDetection.h"

int main() {
    FILE *in1 = fopen("date1.in", "r");
    FILE *out1 = fopen("date1.out", "w");

    // FILE *in2 = fopen("date2.in", "r");
    // FILE *in3 = fopen("date3.in", "r");

    size_t N, M, u, v; // N - numarul de noduri, M - numarul de arce, u - nodul sursa, v - nodul destinatie

    fscanf(in1, "%zu %zu", &N, &M);

    for (size_t i = 0; i < M; ++i) {
        fscanf(in1, "%zu %zu", &u, &v);
        add_edge(u, v);
    }

    if (is_cyclic(N)) {
        fprintf(out1, "are ciclu\n");
    } else {
        fprintf(out1, "nu are ciclu\n");
    }

    fclose(in1);
    fclose(out1);

    return 0;
}
