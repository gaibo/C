/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "huff.h"


int main(int argc, char* argv[]) {
    // get the file to write to from the command line
    FILE* input_file = fopen(argv[1], "w");
    // get the string from the command line
    char* input_str = argv[2];
    
    // run the algorithm, declare names for data that must be freed
    int* occ = occurrences(input_str);
    huff_list* one_tree_list = \
        algorithm(insertion_sort(huff_list_builder(occ)));
    huff* final_huff = one_tree_list->huff;
    char* bin_str = str_to_code(input_str, final_huff);
    unsigned char* compressed_byte_arr = bin_str_to_bits(bin_str);
    
    // print out the required information
    unsigned int n_char_codes = huff_height(final_huff);
    unsigned int n_char_encoded = strlen(bin_str);
    unsigned int n_bytes = ceil((double) n_char_encoded / 8);
    
    fprintf(input_file, "%u\n", n_char_codes);
    key_printer(final_huff, input_file);
    fprintf(input_file, "%u\n", n_char_encoded);
    int i;
    for (i = 0; i < n_bytes; i++) {
        fputc(compressed_byte_arr[i], input_file);
    }
    
    free(compressed_byte_arr);
    free(bin_str);
    free(final_huff);
    free(one_tree_list);
    free(occ);
    fclose(input_file);
    return 0;
}