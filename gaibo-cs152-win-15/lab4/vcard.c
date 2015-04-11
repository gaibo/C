#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
    vcard* vcard_out = malloc(sizeof(vcard));
    vcard_out->cnet = strdup(cnet);
    vcard_out->email = strdup(email);
    vcard_out->fname = strdup(fname);
    vcard_out->lname = strdup(lname);
    vcard_out->tel = strdup(tel);
    return vcard_out;
}

void vcard_free(vcard *c)
{
  free(c->cnet);
  free(c->email);
  free(c->fname);
  free(c->lname);
  free(c->tel);
  free(c);
  return;
}

void vcard_show(vcard *c)
{
  printf("%s, %s, %s, %s, %s\n", c->cnet, c->email, c->fname, c->lname, c->tel);
  return;
}