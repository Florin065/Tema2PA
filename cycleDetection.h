#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100 // dimensiunea maxima a grafului

typedef struct node {
    int val;
    struct node* next;
} node;

void add_edge(size_t u, size_t v);

size_t is_cyclic_util(size_t u);

size_t is_cyclic(size_t n);
