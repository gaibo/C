/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 5 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "huff.h"


/* Construct a singleton Huffman tree from a character and a count. */
huff* huff_singleton(char c, int n) {
    huff* huff_out = malloc(sizeof(huff));
    huff_out->h.leaf.c = c;
    huff_out->h.leaf.n = n;
    return huff_out;
}

/* Return the weight of a Huffman tree. */
int huff_weight(huff* h) {
    switch (h->tag) {
        case LEAF:
            return h->h.leaf.n;
            break;
        case NODE:
            return h->h.node.n;
            break;
        default:
            fprintf(stderr, "error: tag not recognized in huff_weight\n");
            exit(1);
            break;
    }
}

/* Merge two Huffman trees. */
/* See step 2 of the algorithm on the web page for details. */
huff* huff_merge(huff* h1, huff* h2) {
    huff* h_out = malloc(sizeof(huff));
    h_out->tag = NODE;
    h_out->h.node.lsub = h1;
    h_out->h.node.rsub = h2;
    h_out->h.node.n = huff_weight(h1) + huff_weight(h2);
    return h_out;
}

/* Display a Huffman tree at the console. */
/* Essential for development and debugging. */
void huff_show(huff* h) {
    huff_show_helper(h, 0);
    return;
}
void huff_show_helper(huff* h, int tabs) {
    switch (h->tag) {
        case LEAF:
            printf("LEAF: %c %d\n", h->h.leaf.c, h->h.leaf.n);
            break;
        case NODE:
            printf("NODE: %d\n", h->h.node.n);
            int i;
            for (i = 0; i <= tabs; i++) {
                printf("\t");
            }
            huff_show_helper(h->h.node.lsub, tabs+1);
            for (i = 0; i <= tabs; i++) {
                printf("\t");
            }
            huff_show_helper(h->h.node.rsub, tabs+1);
            break;
        default:
            fprintf(stderr, "error: tag not recognized in huff_show\n");
            exit(1);
            break;
    }
    return;
}

/* count the occurrence of each letter by produce an int array
 * of counts for each of the 26 letters and the space character */
int* occurrences(char* str) {
    // allocate int array corresponding to the letters of the alphabet
    int* occ_out = malloc(27 * sizeof(int));
    // initialize with zeroes
    int i_init;
    for (i_init = 0; i_init < 27; i_init++) {
        occ_out[i_init] = 0;
    }
    
    int i;
    char temp_c;
    for (i = 0; str[i] != '\0'; i++) {
        temp_c = str[i];
        if (temp_c == ' ') {
            // count spaces in the 27th slot
            occ_out[26]++;
        } else if (isalpha((int) temp_c)) {
            // count letters
            occ_out[toupper((int) temp_c) - 'A']++;   // ASCII math
        }
    }
    
    return occ_out;
}

/* using the very contrived occurrences int array, produce an unsorted
 * huff_list */
huff_list* huff_list_builder(int* occ_array) {
    char c;
    int n;
    huff_list* prev = NULL;
    
    int i;
    for (i = 0; i < 27; i++) {
        if (occ_array[i] != 0) {
            // allocate a new list node to be linked
            huff_list* list_node = malloc(sizeof(huff_list));
            if (i == 26) {
                // construct a space huff tree and link to list
                c = ' ';
                n = occ_array[i];
                list_node->huff = huff_singleton(c, n);
                list_node->next = prev;
                prev = list_node;
            } else {
                // construct a letter huff tree and link to list
                c = (char) (i+'A');
                n = occ_array[i];
                list_node->huff = huff_singleton(c, n);
                list_node->next = prev;
                prev = list_node;
            }
        }
    }
    
    return prev;
}

/* apply insertion sort to the huff_list */
huff_list* insertion_sort(huff_list* unsorted) {
    return insertion_acc(unsorted, NULL);
}
huff_list* cons(huff_list* hd, huff_list* tl) {
    hd->next = tl;
    return hd;
}
huff_list* hl_insert(huff_list* list_node, huff_list* list) {
    if (list == NULL) {
        list_node->next = NULL;
        return list_node;
    } else if (huff_weight(list_node->huff) <= huff_weight(list->huff)) {
        return cons(list_node, list);
    } else {
        return cons(list, hl_insert(list_node, list->next));
    }
}
huff_list* insertion_acc(huff_list* unsorted, huff_list* sorted) {
    if (unsorted == NULL) {
        return sorted;
    } else {
        huff_list* next_to_sort = unsorted->next;
        return insertion_acc(next_to_sort, hl_insert(unsorted, sorted));
    }
}

/* run the algorithm for coalescing the huff_list */
huff_list* algorithm(huff_list* sorted) {
    // stopping case
    if (sorted->next == NULL) {
        return sorted;
    }
    
    // construct the new node and replace the first two nodes with it
    huff_list* new_node = malloc(sizeof(huff_list));
    new_node->huff = huff_merge(sorted->huff, sorted->next->huff);
    new_node->next = sorted->next->next;
    free(sorted->next);
    free(sorted);
    
    // recurse until there is only one node left
    return algorithm(insertion_sort(new_node));
}

/* find the number of letters that were encoded by finding the 
 * height of the huff_tree */
unsigned int huff_height(huff* huff) {
    switch (huff->tag) {
        case LEAF:
            return 1;
        case NODE:
            return 1 + my_max(huff_height(huff->h.node.lsub), \
                              huff_height(huff->h.node.rsub));
        default:
            fprintf(stderr, "error: tag not recognized in huff_height\n");
            exit(1);
    }
}
unsigned int my_max(unsigned int a, unsigned int b) {
    return (a > b) ? a : b;
}

/* print the huffman codes with this janky printer */
void key_printer(huff* huff) {
    unsigned int height = huff_height(huff);
    // given the height of the tree, there will be at most height-1 digits
    // in the binary string accumulator plus an extra null ending
    char* bin_str_acc = malloc(height * sizeof(char));
    key_printer_helper(huff, bin_str_acc, 0);
    free(bin_str_acc);
    return;
}
void key_printer_helper(huff* huff, char* bin_str_acc, \
                           unsigned int end_place) {
    switch (huff->tag) {
        case LEAF:
            // end it and print it
            bin_str_acc[end_place] = '\0';
            printf("%c = %s\n", huff->h.leaf.c, bin_str_acc);
            return;
        case NODE:
            // append the desired binary digit and recurse
            bin_str_acc[end_place] = '0';
            key_printer_helper(huff->h.node.lsub, bin_str_acc, end_place+1);
            bin_str_acc[end_place] = '1';
            key_printer_helper(huff->h.node.rsub, bin_str_acc, end_place+1);
            return;
        default:
            fprintf(stderr, "error: tag not recognized in huff_height\n");
            exit(1);
    }
}

/* given a letter and the huff tree, return the binary string code */
char* code_generator(char letter, huff* huff) {
    unsigned int height = huff_height(huff);
    // given the height of the tree, there will be at most height-1 digits
    // in the binary string accumulator plus an extra null ending
    char* bin_str_acc = malloc(height * sizeof(char));
    code_generator_helper(letter, huff, bin_str_acc);
    return bin_str_acc;
}
void code_generator_helper(char letter, huff* huff, char* bin_str_acc) {
    if (huff->tag == NODE) {
        if (huff->h.node.lsub->tag == LEAF) {
            if (huff->h.node.lsub->h.leaf.c == toupper((int) letter)) {
                *bin_str_acc = '0';
                *(bin_str_acc+1) = '\0';
                return;
            }
        } else if (huff->h.node.lsub->tag == NODE) {
            *bin_str_acc = '0';
            code_generator_helper(letter, huff->h.node.lsub, bin_str_acc+1);
        }
        
        if (huff->h.node.rsub->tag == LEAF) {
            if (huff->h.node.rsub->h.leaf.c == toupper((int) letter)) {
                *bin_str_acc = '1';
                *(bin_str_acc+1) = '\0';
                return;
            }
        } else if (huff->h.node.rsub->tag == NODE) {
            *bin_str_acc = '1';
            code_generator_helper(letter, huff->h.node.rsub, bin_str_acc+1);
        }
    } else {
        fprintf(stderr, "error: huff tree starts with a LEAF\n");
        exit(1);
    }
}

/* print a full converted string */
void string_convert_and_print(char* input_str, huff* huff) {
    int i;
    for (i = 0; input_str[i] != '\0'; i++) {
        char* code = code_generator(input_str[i], huff);
        printf("%s", code);
        free(code);
    }
    printf("\n");
    return;
}