#include <stdio.h>
#include <stdlib.h>

#include "iq.h"
#include "graph.h"

il *bfs(graph *g, unsigned int start_key)
{
  il *prev_reached, *reached;
  reached = NULL;
  iq *q = iq_new();
  if (start_key>=g->n_vertices) {
    fprintf(stderr,"bfs: no such vertex (%u)\n",start_key);
    exit(1);
  }
  enqueue(q,start_key);
  while (q->n>0) {
    int curr = dequeue(q);
    if (g->vs[curr]->done)
      continue;
    g->vs[curr]->done = 1;
    prev_reached = reached;
    reached = il_append(prev_reached,il_singleton(curr));
    il_free(prev_reached);
    il *neighbors = g->es[curr];
    while (neighbors) {
      int n = neighbors->n;
      enqueue(q,n);
      neighbors = neighbors->next;
    }
  }
  iq_free(q);
  return reached;
}

int main(int argc, char *argv[])
{
  graph *g;
  if (argc>1) {
    g = sample_graph(atoi(argv[1]));
  } else {
    g = sample_graph(0);
  }

  printf("--- graph ---\n");
  graph_show(g);
  putchar('\n');

  printf("--- breadth-first search ---\n");
  il *ns = bfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);
  return 0;
}