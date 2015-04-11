#include "vx.h"

vertex *vertex_new(unsigned int key, char *label)
{
  vertex *v = (vertex*)malloc(sizeof(vertex));
  if (v==NULL) {
    fprintf(stderr,"vertex_new: allocation failed\n");
    exit(1);
  }
  v->key = key;
  v->label = strdup(label);
  v->done = 0;
  return v;
}

void vertex_free(vertex *v)
{
  free(v->label);
  free(v);
}

void vertex_show(vertex *v)
{
  printf("vertex(%u,\"%s\",%s)",v->key,v->label,v->done?"done":"not done");
}