#include <stdio.h>
#include <stdlib.h>

#include "is.h"
#include "graph.h"

il *dfs(graph *g, unsigned int start_key)
{
  il *prev_reached, *reached;
  reached = NULL;
  is *s = is_new();
  if (start_key>=g->n_vertices) {
    fprintf(stderr,"dfs: no such vertex (%u)\n",start_key);
    exit(1);
  }
  push(s,start_key);
  while (s->ns!=NULL) {
    int curr = pop(s);
    if (g->vs[curr]->done)
      continue;
    prev_reached = reached;
    reached = il_append(reached,il_singleton(curr));
    il_free(prev_reached);
    g->vs[curr]->done = 1;
    il *neighbors = g->es[curr];
    while (neighbors) {
      int n = neighbors->n;
      push(s,n);
      neighbors = neighbors->next;
    }
  }
  is_free(s);
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

  printf("--- depth-first search ---\n");
  il *ns = dfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);
  return 0;
}