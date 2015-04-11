/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 6 */

#include <stdio.h>
#include <stdlib.h>
#include "huff.h"


void evidence_occurrences(void) {
    int* array = occurrences("senselessness");
    int i;
    for (i = 0; i < 27; i++) {
        printf("%d\n", array[i]);
    }
    free(array);
    return;
}

void huff_list_print(huff_list* list) {
    while (list != NULL) {
        huff_show(list->huff);
        list = list->next;
    }
    return;
}

void evidence_huff_list_builder(void) {
    int* array = occurrences("senselessness");
    huff_list* list = huff_list_builder(array);
    huff_list_print(list);
    free(array);
    free(list);
    return;
}

void evidence_hl_insert(void) {
    int* array = occurrences("senselessness");
    huff_list* list = huff_list_builder(array);
    huff_list* node1 = list;
    huff_list* node2 = list->next;
    huff_list* node3 = list->next->next;
    huff_list* node4 = list->next->next->next;
    huff_list* inserted_list = hl_insert(node1, NULL);
    inserted_list = hl_insert(node2, inserted_list);
    inserted_list = hl_insert(node3, inserted_list);
    inserted_list = hl_insert(node4, inserted_list);
    huff_list_print(inserted_list);
    free(array);
    free(inserted_list);
    return;
}

void evidence_insertion_sort(void) {
    int* array = occurrences("senselessness");
    huff_list* list = huff_list_builder(array);
    huff_list* sorted_list = insertion_sort(list);
    huff_list_print(sorted_list);
    free(array);
    free(sorted_list);
    return;
}

void huff_test(void) {
    huff_list* one_tree_list = \
        algorithm(insertion_sort(huff_list_builder(occurrences("senselessness"))));
    huff_show(one_tree_list->huff);
    printf("%u letters encoded\n", huff_height(one_tree_list->huff));
    printf("%s\n", code_generator('s', one_tree_list->huff));
    free(one_tree_list->huff);
    free(one_tree_list);
    return;
}

int main() {
    evidence_occurrences();
    printf("********\n");
    evidence_huff_list_builder();
    printf("********\n");
    evidence_hl_insert();
    printf("********\n");
    evidence_insertion_sort();
    printf("********\n");
    huff_test();
    return 0;
}