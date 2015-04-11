/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"


unsigned long int good_hash(char* s) {
    unsigned long int res = 17;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        res = 37*res + s[i];
    }
    return res;
}

unsigned long int bad_hash(char* s) {
    unsigned long int res = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        res += s[i];
    }
    return res;
}

htbl* ht_new(unsigned long int (*h)(char*), unsigned int sz) {
    htbl* htbl_out = malloc(sizeof(htbl));
    htbl_out->buckets = malloc(sz * sizeof(sll*));
    unsigned int i;
    for (i = 0; i < sz; i++) {
        htbl_out->buckets[i] = NULL;
    }
    htbl_out->hash = h;
    htbl_out->n_buckets = sz;
    return htbl_out;
}

unsigned int ht_n_entries(htbl* t) {
    unsigned int acc = 0;
    
    unsigned int i;
    for (i = 0; i < t->n_buckets; i++) {
        acc += sll_length(t->buckets[i]);
    }
    
    return acc;
}

double ht_load_factor(htbl* t) {
    return (double) ht_n_entries(t) / t->n_buckets;
}

unsigned int ht_max_bucket(htbl* t) {
    unsigned int curr_max = 0;   // initialize max
    
    unsigned int temp_list_length;
    unsigned int i;
    for (i = 0; i < t->n_buckets; i++) {
        temp_list_length = sll_length(t->buckets[i]);
        if (temp_list_length > curr_max) {
            curr_max = temp_list_length;
        }
    }
    
    return curr_max;
}

unsigned int ht_ins(char* s, htbl* t) {
    unsigned int chosen_bucket = (*(t->hash))(s) % t->n_buckets;
    t->buckets[chosen_bucket] = sll_cons(s, t->buckets[chosen_bucket]);
    return sll_length(t->buckets[chosen_bucket]);
}

void ht_ins_list(sll* ss, htbl* t) {
    while (ss != NULL) {
        ht_ins(ss->s, t);
        ss = ss->next;
    }
    return;
}

int ht_member(char* s, htbl* t) {
    unsigned int chosen_bucket = (*(t->hash))(s) % t->n_buckets;
    return sll_member(s, t->buckets[chosen_bucket]);
}

void ht_show(htbl* t) {
    unsigned int i;
    for (i = 0; i < t->n_buckets; i++) {
        printf("%u: ", i);
        sll_show(t->buckets[i]);
        printf("\n\n");
    }
    return;
}

void ht_free(htbl* t) {
    unsigned int i;
    for (i = 0; i < t->n_buckets; i++) {
        sll_free(t->buckets[i]);
    }
    free(t->buckets);
    free(t);
    return;
}