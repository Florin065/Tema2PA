#include "cycleDetection.h"

void init_graph(graph *G) {
    for (size_t i = 1; i < MAX_NODES; i++) {
        G->adj[i] = NULL;
        G->visited[i] = 0;
        G->recursion_stack[i] = 0;
    }
}

void add_edge(graph *G, size_t u, size_t v) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->val = v;
    new_node->next = G->adj[u];
    G->adj[u] = new_node;
}

bool is_cyclic_util(graph *G, size_t u) {
    G->visited[u] = 1;
    G->recursion_stack[u] = 1;
    for (node *v = G->adj[u]; v; v = v->next) {
        if (!G->visited[v->val] && is_cyclic_util(G, v->val)) {
            return 1;
        } else if (G->recursion_stack[v->val]) {
            return 1;
        }
    }

    G->recursion_stack[u] = 0;

    return 0;
}

bool is_cyclic(graph *G, size_t n) {
    for (size_t i = 1; i <= n; i++) {
        G->visited[i] = 0;
        G->recursion_stack[i] = 0;
    }

    for (size_t i = 1; i <= n; i++) {
        if (!G->visited[i] && is_cyclic_util(G, i)) {
            return 1;
        }
    }

    return 0;
}