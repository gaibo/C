#include "iq.h"

iq *iq_new()
{
  iq *q = (iq*)malloc(sizeof(iq));
  if (q==NULL) {
    fprintf(stderr,"iq_new: malloc failed\n");
    exit(1);
  }
  q->n = 0;
  q->front = q->back = NULL;
  return q;
}

void enqueue(iq *q, int n)
{
  if (q->n==0)
    q->front = q->back = il_singleton(n);
  else
    q->back = (q->back->next = il_singleton(n));
  q->n++;
}

int dequeue(iq *q)
{
  if (q->n==0) {
    fprintf(stderr,"dequeue error: empty\n");
    exit(1);
  }
  int n = q->front->n;
  if (q->n==1) {
    free(q->front);
    q->front = q->back = NULL;
  } else {
    il *curr = q->front->next;
    free(q->front);
    q->front=curr;
  }
  q->n--;
  return n;
}

void iq_show(iq *q)
{
  printf("begin queue (%d items, front shown at left))\n",q->n);
  printf("  ");
  il_show(q->front);
  printf("end queue\n");
}

void iq_free(iq *q) {
    il_free(q->front);
    free(q);
    return;
}