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

htbl* ht_new(unsigned long int(*h)(char*), unsigned int sz) {
    htbl* htbl_out = malloc(sizeof(htbl));
    htbl_out->hash = h;
    htbl_out->n_buckets = sz;
    htbl_out->buckets = malloc(sz * sizeof(sll*));
    int i;
    for (i = 0; i < sz; i++) {
        htbl_out->buckets[i] = NULL;
    }
    return htbl_out;
}

unsigned int ht_n_entries(htbl* t) {
    unsigned int acc = 0;
    int i;
    for (i = 0; i < t->n_buckets; i++) {
        acc += sll_length(t->buckets[i]);
    }
    return acc;
}

double ht_load_factor(htbl* t) {
    return (double)ht_n_entries(t) / t->n_buckets;
}

unsigned int ht_max_bucket(htbl* t) {
    unsigned int curr_max = 0;
    unsigned int temp_list_length;
    int i;
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
    int i;
    for (i = 0; i < t->n_buckets; i++) {
        printf("%u: ", i);
        sll_show(t->buckets[i]);
        printf("\n");
    }
    return;
}

void ht_free(htbl* t) {
    int i;
    for (i = 0; i < t->n_buckets; i++) {
        sll_free(t->buckets[i]);
    }
    free(t->buckets);
    free(t);
    return;
}

int is_prime(unsigned int number) {
    int i;
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
    if (current <= 2) {
        fprintf(stderr, "error in previous_prime: no previous primes\n");
        exit(1);
    }
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
    
    // resize with new prime number of buckets
    unsigned int new_n_buckets;
    unsigned int n_entries = ht_n_entries(*t);
    if (load_factor > 1.2) {
        new_n_buckets = next_prime(floor(n_entries/1.2));
    } else if (load_factor < 0.8) {
        new_n_buckets = previous_prime(ceil(n_entries/0.8));
    } else {
        fprintf(stderr, "error in ht_resize: unexpected case in resizing\n");
        exit(1);
    }
    
    // copy all strings over to resized hash table
    htbl* ht_resized = ht_new((*t)->hash, new_n_buckets);
    int i;
    for (i = 0; i < (*t)->n_buckets; i++) {
        ht_ins_list((*t)->buckets[i], ht_resized);
    }
    
    ht_free(*t);
    *t = ht_resized;
    return;
}