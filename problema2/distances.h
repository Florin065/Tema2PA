#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

extern size_t n, m, s;
extern size_t **adj;
extern size_t *dist;
extern size_t *visited;
extern size_t *topo;
extern size_t topo_size;

void dfs(size_t u);

void topological_sort();

void calculate_distances();