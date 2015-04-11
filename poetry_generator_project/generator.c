#include "htbl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* alloc_str(unsigned int sz) {
    char* s = malloc(sz);
    if (s == NULL) {
        fprintf(stderr,"malloc failed in alloc_str\n");
        exit(1);
    }
    int i;
    for (i = 0; i < sz; i++) {
        s[i] = '\0';
    }
    return s;
}

char* trim_to_word(char* s) {
    int n = strlen(s);
    if (!isalpha((int)s[n-1])) { // remove punctuation if there is any
        s[n-1] = '\0';
    }
    char* word = strdup(s);
    return word;
}

int main(void) {
    // create a hash table to hold words
    htbl* t = ht_new(&good_hash, 10);
    
    // fill hash table with words from input_poems.txt
    FILE* input_poems = fopen("input_poems.txt", "r");
    if (input_poems == NULL) {
        fprintf(stderr, "couldn't open file in main\n");
        exit(1);
    }
    while (!feof(input_poems)) {
        char* str = alloc_str(256);
        fscanf(input_poems, "%s", str);
        char* word = trim_to_word(str);
        free(str);
        if (strlen(word) > 0) {
            ht_ins(word, t);
        }
        free(word);
    }
    fclose(input_poems);

    // resize hash table for efficiency
    ht_resize(&t);
    
    // show some stats
    ht_show(t);
    printf("The hash table has %u buckets with %u entries (load factor %lg).\n\n",
        t->n_buckets, 
        ht_n_entries(t),
        ht_load_factor(t));
    printf("The bucket with the most items in it contains %u items.\n",
        ht_max_bucket(t));
    
    ht_free(t);
    return 0;
}