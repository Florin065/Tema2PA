#include "cycleDetection.h"

node *adj[MAX_N];
size_t visited[MAX_N];
size_t recursion_stack[MAX_N];

void add_edge(size_t u, size_t v) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->val = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

bool is_cyclic_util(size_t u) {
    visited[u] = 1;
    recursion_stack[u] = 1;

    for (node *v = adj[u]; v; v = v->next) {
        if (!visited[v->val] && is_cyclic_util(v->val)) {
            return true;
        } else if (recursion_stack[v->val]) {
            return true;
        }
    }

    recursion_stack[u] = 0;

    return false;
}

bool is_cyclic(size_t N) {
    for (size_t i = 1; i <= N; i++) {
        visited[i] = 0;
        recursion_stack[i] = 0;
    }

    for (size_t i = 1; i <= N; i++) {
        if (visited[i] == 0 && is_cyclic_util(i)==1) {
            return true;
        }
    }

    return false;
}