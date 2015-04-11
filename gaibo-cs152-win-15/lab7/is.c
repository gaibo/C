#include "is.h"

is *is_new() 
{
  is *s = (is*)malloc(sizeof(is));
  if (s==NULL) {
    fprintf(stderr,"is_new: malloc failed\n");
    exit(1);
  }
  s->ns = NULL;
  return s;
}

void push(is *s, int n)
{
  s->ns = il_cons(n,s->ns);
}

int pop(is *s)
{
  if (s) {
    int n = s->ns->n;
    il* next = s->ns->next;
    free(s->ns);
    s->ns = next;
    return n;
  } else {
    fprintf(stderr,"pop: empty\n");
    exit(1);
  }
}

void is_show(is *s)
{  
  printf("begin stack (%d items, top shown at left)\n",il_len(s->ns));
  printf("  ");
  il_show(s->ns);
  printf("end stack\n");
}

void is_free(is *s) {
    il_free(s->ns);
    free(s);
    return;
}