/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 5 */

#include <stdio.h>
#include <stdlib.h>
#include "huff.h"


int main(int argc, char* argv[]) {
    char* input_str = argv[1];
    int* occ = occurrences(input_str);
    huff_list* one_tree_list = \
        algorithm(insertion_sort(huff_list_builder(occ)));
    huff* final_huff = one_tree_list->huff;
    
    printf("%u\n", huff_height(final_huff));
    key_printer(final_huff);
    string_convert_and_print(input_str, final_huff);
    
    free(final_huff);
    free(one_tree_list);
    free(occ);
    return 0;
}