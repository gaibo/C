/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_list.h"


int sl_sorted_asc(string_list* ss) {
    // special case: empty list is sorted in ascending order
    if (ss == NULL) {
        return 1;
    }
    
    // base case: next node is NULL (last node is reached)
    if (ss->next == NULL) {
        return 1;
    }
    
    // recursion
    if (strcmp(ss->val, ss->next->val) <= 0) {
        return sl_sorted_asc(ss->next);
    } else {
        return 0;
    }
}

string_list* cons_create(char* s, string_list* tl) {
    string_list* hd = malloc(sizeof(string_list));
    hd->val = malloc((strlen(s)+1) * sizeof(char));
    hd->val = s;
    hd->next = tl;
    return hd;
}

void cons_link(string_list* hd, string_list* tl) {
    hd->next = tl;
    return;
}

string_list* sl_insert(char* s, string_list* ss) {
    if (ss == NULL || strcmp(s, ss->val) <= 0) {
        // if given empty list or if strcmp indicates before
        return cons_create(s, ss);
    } else {
        // proceed down the list
        cons_link(ss, sl_insert(s, ss->next));
        return ss;
    }
}

string_list* sl_filter(int (*test)(char*), string_list* ss) {
    if (ss == NULL) {
        return NULL;
    } else {
        if ((*test)(ss->val)) {
            cons_link(ss, sl_filter(test, ss->next));
            return ss;
        } else {
            string_list* new_start = ss->next;
            free(ss->val);
            free(ss);
            return sl_filter(test, new_start);
        }
    }
}