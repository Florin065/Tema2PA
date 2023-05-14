#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"

#define MAX_N 100 // dimensiunea maxima a grafului

typedef struct node {
    size_t val;
    struct node *next;
} node;

void add_edge(size_t u, size_t v);

bool is_cyclic_util(size_t u);

bool is_cyclic(size_t n);