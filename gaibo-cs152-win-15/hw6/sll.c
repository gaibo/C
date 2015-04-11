/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"


sll* sll_cons(char* s, sll* ss) {
    sll* head_new = malloc(sizeof(sll));
    head_new->s = strdup(s);
    head_new->next = ss;
    return head_new;
}

unsigned int sll_length(sll* ss) {
    unsigned int acc = 0;
    while (ss != NULL) {
        acc++;
        ss = ss->next;
    }
    return acc;
}

int sll_member(char* s, sll* ss) {
    while (ss != NULL) {
        if (strcmp(ss->s, s) == 0) {
            return 1;
        }
        ss = ss->next;
    }
    return 0;
}

void sll_show(sll* ss) {
    while (ss != NULL) {
        printf("%s | ", ss->s);
        ss = ss->next;
    }
    return;
}

void sll_free(sll* ss) {
    // case of empty list, don't need to free links
    if (ss == NULL) {
        return;
    }
    
    // follow the links to the end, then start freeing
    if (ss->next != NULL) {
        sll_free(ss->next);
    }
    free(ss);
    
    return;
}