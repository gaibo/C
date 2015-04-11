#include "htbl.h"


char* alloc_str(int sz) {
    char* s = malloc(sz);
    if (s == NULL) {
        fprintf(stderr,"alloc_str: malloc failed\n");
        exit(1);
    }
    int i;
    for (i = 0; i < sz; i++) {
        s[i] = '\0';
    }
    return s;
}

char* trim_newline(char* s) {
    char* t;
    int n = strlen(s);
    int must_change = (s[n-1] == '\n');
    if (must_change) {
        s[n-1] = '\0';
    }
    t = strdup(s);
    if (must_change) {
        s[n-1] = '\n';
    }
    return t;
}

int main(void) {
    printf("*****testing hash table*****\n\n");
    htbl* t = ht_new(&good_hash, 10);
    
    FILE* cnets2015 = fopen("cnets2015", "r");
    while (!feof(cnets2015)) {
        char* s = alloc_str(256);
        fgets(s, 256, cnets2015);
        char* l = trim_newline(s);
        free(s);
        if (strlen(l) > 0) {
            ht_ins(l, t);
        }
        free(l);
    }
    fclose(cnets2015);
    
    ht_show(t);
    printf("The hash table has %u buckets with %u entries (load factor %lg).\n\n",
        t->n_buckets, 
        ht_n_entries(t),
        ht_load_factor(t));
    printf("The bucket with the most items in it contains %u items.\n\n",
        ht_max_bucket(t));
    printf("ht_member:\n");
    printf("membership of cnet \"aardvark\" : %i\n", ht_member("aardvark", t));
    printf("membership of cnet \"borja\"    : %i\n", ht_member("borja", t));
    printf("\n");
    
    // resize
    printf("***now resizing***\n");
    ht_resize(&t);
    printf("***resizing complete***\n\n");
    
    // do everything again
    ht_show(t);
    printf("The hash table has %u buckets with %u entries (load factor %lg).\n\n",
        t->n_buckets, 
        ht_n_entries(t),
        ht_load_factor(t));
    printf("The bucket with the most items in it contains %u items.\n\n",
        ht_max_bucket(t));
    printf("ht_member:\n");
    printf("membership of cnet \"aardvark\" : %i\n", ht_member("aardvark", t));
    printf("membership of cnet \"borja\"    : %i\n", ht_member("borja", t));
    printf("\n");
    
    ht_free(t);
    return 0;
}