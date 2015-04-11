#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

bst *bst_singleton(vcard *c)
{
    bst* bst_out = malloc(sizeof(bst));
    bst_out->c = c;
    bst_out->lsub = NULL;
    bst_out->rsub = NULL;
    return bst_out;
}

int bst_insert(bst *t, vcard *c)
{
    // return error if empty tree is given
    if (t == NULL) {
        fprintf(stderr, "error: empty tree in bst_insert\n");
        exit(1);
    }
    
    return bst_insert_helper(t, c); // cue the recursion
}
int bst_insert_helper(bst* t, vcard* c) {
    // short-circuit if cnet is already there
    if (!strcmp(c->cnet, t->c->cnet)) {
        return 0;
    }
    
    // recursive step
    if (strcmp(c->cnet, t->c->cnet) < 0) {
        if (t->lsub == NULL) {
            t->lsub = bst_singleton(c);
        } else {
            bst_insert_helper(t->lsub, c);
        }
    } else if (strcmp(c->cnet, t->c->cnet) > 0) {
        if (t->rsub == NULL) {
            t->rsub = bst_singleton(c);
        } else {
            bst_insert_helper(t->rsub, c);
        }
    }
    return 1;
}

unsigned int bst_num_entries(bst *t)
{
    // special case: empty tree given
    if (t == NULL) {
        return 0;
    }
    
    // base case: leaf node (singleton tree)
    if (t->lsub == NULL && t->rsub == NULL) {
        return 1;
    }
    
    // recursive step
    return 1 + bst_num_entries(t->lsub) + bst_num_entries(t->rsub);
}

unsigned int bst_height(bst *t)
{
    // base case: empty tree
    if (t == NULL) {
        return 0;
    }
    
    // recursive step
    return 1 + my_max(bst_height(t->lsub), bst_height(t->rsub));
}
unsigned int my_max(int a, int b) {
    return (a > b) ? a : b;
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
    *n_comparisons = 0;
    return bst_search_helper(t, cnet, n_comparisons);
}
vcard* bst_search_helper(bst *t, char *cnet, int *n_comparisons) {
    // return NULL if a dead end is hit and no cnet matched
    if (t == NULL) {
        return NULL;
    }
    
    // if not a dead end, a comparison will be made
    (*n_comparisons)++;
    
    // compare
    if (strcmp(cnet, t->c->cnet) < 0) {
        return bst_search_helper(t->lsub, cnet, n_comparisons);
    } else if (strcmp(cnet, t->c->cnet) > 0) {
        return bst_search_helper(t->rsub, cnet, n_comparisons);
    } else {
        return t->c;
    }
}

unsigned int bst_c(bst *t, char c)
{
    // base case: empty tree (end of the search)
    if (t == NULL) {
        return 0;
    }
    
    // recursive case 1: match found
    // must go down both branches
    if (c == t->c->cnet[0]) {
        printf("%s\n", t->c->cnet);
        return 1 + bst_c(t->lsub, c) + bst_c(t->rsub, c);
    }
    
    // recursive case 2: no match
    // go down the correct branch
    if (c < t->c->cnet[0]) {
        return bst_c(t->lsub, c);
    } else if (c > t->c->cnet[0]) {
        return bst_c(t->rsub, c);
    } else {
        fprintf(stderr, "error in bst_c: impossible comparison\n");
        exit(1);
    }
}

void bst_free(bst *t)
{
    if (t == NULL) {
        return;
    }
    
    bst_free(t->lsub);
    bst_free(t->rsub);
    
    // once the leaves are reached, start freeing
    vcard_free(t->c);
    free(t);
    return;
}