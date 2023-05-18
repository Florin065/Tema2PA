#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100000

typedef struct node {
    size_t val;
    struct node *next;
} node;

typedef struct {
    node *adj[MAX_NODES];
    size_t visited[MAX_NODES];
    size_t recursion_stack[MAX_NODES];
} graph;

void init_graph(graph *G);

void add_edge(graph *G, size_t u, size_t v);

bool is_cyclic_util(graph *G, size_t u);

bool is_cyclic(graph *G, size_t n);