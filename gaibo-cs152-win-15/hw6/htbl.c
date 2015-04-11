/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

unsigned int is_prime(unsigned int number) {
    unsigned int i;
    unsigned int stopping_point = sqrt(number);
    for (i = 2; i <= stopping_point; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

unsigned int next_prime(unsigned int current) {
    unsigned int next = current + 1;
    if (is_prime(next)) {
        return next;
    } else {
        return next_prime(next);
    }
}

unsigned int previous_prime(unsigned int current) {
    unsigned int previous = current - 1;
    if (is_prime(previous)) {
        return previous;
    } else {
        return previous_prime(previous);
    }
}

void ht_resize(htbl** t) {
    // short-circuit if conditions are already good
    double load_factor = ht_load_factor(*t);
    if (load_factor == 0 || (load_factor >= 0.8 && load_factor <= 1.2)) {
        return;
    }
    
    // resize
    unsigned int new_n_buckets;
    if (load_factor > 1.2) {
        new_n_buckets = next_prime(floor(ht_n_entries(*t)/1.2));
    } else if (load_factor < 0.8) {
        new_n_buckets = previous_prime(ceil(ht_n_entries(*t)/0.8));
    }
    
    htbl* ht_resized = ht_new((*t)->hash, new_n_buckets);
    unsigned int i;
    for (i = 0; i < (*t)->n_buckets; i++) {
        ht_ins_list((*t)->buckets[i], ht_resized);
    }
    
    ht_free(*t);
    *t = ht_resized;
    return;
}