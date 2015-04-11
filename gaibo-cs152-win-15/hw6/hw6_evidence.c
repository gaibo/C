/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ss.h"
#include "sll.h"
#include "htbl.h"
#include "matrix.h"


void squeeze_evidence(void) {
    printf("***testing squeeze\n");
    squeezed_string* ss_1 = squeeze("TEST");
    char first_letter = ss_read(ss_1, 0);
    char second_letter = ss_read(ss_1, 1);
    char third_letter = ss_read(ss_1, 2);
    char fourth_letter = ss_read(ss_1, 3);
    printf("first letter - expecting T: %c\n", first_letter);
    printf("second letter - expecting E: %c\n", second_letter);
    printf("third letter - expecting S: %c\n", third_letter);
    printf("fourth letter - expecting T: %c\n", fourth_letter);
    free(ss_1);
    return;
}

void unsqueeze_evidence(void) {
    printf("***testing unsqueeze\n");
    squeezed_string* ss_1 = squeeze("test TEST test");
    squeezed_string* ss_2 = squeeze("abc");
    char* string_1 = unsqueeze(ss_1);
    char* string_2 = unsqueeze(ss_2);
    printf("reconstructed string - expecting TEST TEST TEST: %s\n", string_1);
    printf("reconstructed string - expecting ABC: %s\n", string_2);
    free(ss_1);
    free(ss_2);
    free(string_1);
    free(string_2);
    return;
}

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

void ht_resize_evidence(void) {
    printf("***testing ht_resize along with the old htbl stuff\n");
    htbl* t = ht_new(&good_hash, 10);
    
    FILE* cnets2015 = fopen("cnets2015", "r");
    while (!feof(cnets2015)) {
        char* s = alloc_str(256);
        char* l;
        fgets(s, 256, cnets2015);
        l = trim_newline(s);
        free(s);
        if (strlen(l) > 0) {
            ht_ins(l, t);
        }
        free(l);
    }
    fclose(cnets2015);
    
    ht_show(t);
    printf("The hash table has %i buckets with %i entries (load factor %lg).\n",
        t->n_buckets, 
        ht_n_entries(t),
        ht_load_factor(t));
    printf("\nThe bucket with the most items in it contains %d items.\n",
        ht_max_bucket(t));
    printf("\nht_member:\n");
    printf("membership of cnet \"aardvark\" : %i\n", ht_member("aardvark",t));
    printf("membership of cnet \"borja\"    : %i\n", ht_member("borja",t));
    
    printf("\n**now resizing**\n");
    htbl** pointer_to_t = malloc(sizeof(htbl*));
    pointer_to_t = &t;
    ht_resize(pointer_to_t);
    printf("**resizing complete**\n\n");
    
    // testing the whole shebang to make sure the hashtable still works
    ht_show(t);
    printf("The hash table has %i buckets with %i entries (load factor %lg).\n",
        t->n_buckets, 
        ht_n_entries(t),
        ht_load_factor(t));
    printf("\nThe bucket with the most items in it contains %d items.\n",
        ht_max_bucket(t));
    printf("\nht_member:\n");
    printf("membership of cnet \"aardvark\" : %i\n", ht_member("aardvark",t));
    printf("membership of cnet \"borja\"    : %i\n", ht_member("borja",t));
    
    ht_free(t);
    return;
}

void matrix_zero_evidence(void) {
    printf("***testing matrix_zero\n");
    matrix* m = matrix_zero(3, 5);
    printf("3x5 zero matrix:\n");
    matrix_show(m);
    matrix_free(m);
    return;
}

void matrix_read_write_evidence(void) {
    printf("***testing matrix_read and matrix_write\n");
    matrix* m = matrix_zero(5, 5);
    printf("5x5 zero matrix\n");
    matrix_show(m);
    printf("%f is the value at %u, %u in the matrix\n", matrix_read(m, 3, 4), 3, 4);
    matrix_write(m, 3, 4, 2.4);
    printf("5x5 zero matrix with something written\n");
    matrix_show(m);
    printf("%f is now the value at %u, %u in the matrix\n", matrix_read(m, 3, 4), 3, 4);
    matrix_free(m);
    return;
}

void matrix_add_evidence(void) {
    printf("***testing matrix_add\n");
    matrix* m = matrix_zero(2, 1);
    matrix* n = matrix_zero(2, 1);
    matrix_write(m, 0, 0, 1.6);
    matrix_write(m, 1, 0, 0.8);
    matrix_write(n, 0, 0, -1.5);
    matrix_write(n, 1, 0, -0.9);
    printf("matrix m:\n");
    matrix_show(m);
    printf("matrix n:\n");
    matrix_show(n);
    matrix* sum = matrix_add(m, n);
    printf("sum matrix:\n");
    matrix_show(sum);
    matrix_free(m);
    matrix_free(n);
    matrix_free(sum);
    return;
}

void matrix_mult_evidence(void) {
    printf("***testing matrix_mult\n");
    matrix* m = matrix_zero(2, 1);
    matrix* n = matrix_zero(1, 2);
    matrix_write(m, 0, 0, 1.0);
    matrix_write(m, 1, 0, 2.0);
    matrix_write(n, 0, 0, 3.0);
    matrix_write(n, 0, 1, 4.0);
    printf("matrix m:\n");
    matrix_show(m);
    printf("matrix n:\n");
    matrix_show(n);
    matrix* product = matrix_mult(m, n);
    printf("product matrix:\n");
    matrix_show(product);
    matrix_free(m);
    matrix_free(n);
    matrix_free(product);
    return;
}

/*****************************************************************************/

int main() {
    squeeze_evidence();
    printf("\n");
    unsqueeze_evidence();
    printf("\n");
    ht_resize_evidence();
    printf("\n");
    matrix_zero_evidence();
    printf("\n");
    matrix_read_write_evidence();
    printf("\n");
    matrix_add_evidence();
    printf("\n");
    matrix_mult_evidence();
    return 0;
}