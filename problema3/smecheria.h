#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_COST 30
#define INF INT_MAX

typedef struct {
    size_t vertex;
    size_t weight;
} Edge;

typedef struct {
    Edge *edges;
    size_t count;
    size_t capacity;
} Vertex;

extern Vertex *graph;
extern size_t *dist;
extern size_t n;

void allocate_arrays();

void free_arrays();

void add_edge(size_t u, size_t v, size_t w);

void dijkstra(size_t source);