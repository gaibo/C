/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "ss.h"


void ss_write(squeezed_string* ss, unsigned int i, char c) {
    // error if the ss array doesn't have an ith character encoded
    if (i >= ss->clen) {
        fprintf(stderr, "error: writing out of bounds\n");
        exit(1);
    }
    c = toupper((int) c);   // dealing only with upper case
    // error if c is not a space or a capital letter
    if (c != ' ' && (c < 'A' || c > 'Z')) {
        fprintf(stderr, "error: writing unknown char\n");
        exit(1);
    }
    
    // convert c to preliminary squeezed version
    unsigned char squeezed_c;
    if (c == ' ') {
        squeezed_c = (unsigned char) (c - ' ');   // 000[00000]
    } else {
        squeezed_c = (unsigned char) (c - 64);    // 000[5-bit code]
    }
    // create a mask of 11111 for where the new 5-bit code will go
    unsigned char mask = 31;    // 000[11111]
    
    // find element of array to start at and gap before the desired bit
    int bit_to_start = i * 5;
    int byte_to_start = bit_to_start / 8;
    int front_gap = bit_to_start - byte_to_start*8;
    
    if (front_gap > 3) {
        // use fancy shifting to deal with spacing between 2 bytes
        unsigned char shifted_squeezed_c_1 = squeezed_c >> (front_gap-3);
        unsigned char shifted_mask_1 = mask >> (front_gap-3);
        unsigned char shifted_squeezed_c_2 = squeezed_c << (8-(front_gap-3));
        unsigned char shifted_mask_2 = mask << (8-(front_gap-3));
        // &~mask to clean, then | the new 5-bit code in (x2)
        ss->array[byte_to_start] = (ss->array[byte_to_start] & ~shifted_mask_1)
                                  | shifted_squeezed_c_1;
        ss->array[byte_to_start+1] = (ss->array[byte_to_start+1] & ~shifted_mask_2)
                                    | shifted_squeezed_c_2;
    } else {
        // use shifting to deal with spacing
        unsigned char shifted_squeezed_c = squeezed_c << (3-front_gap);
        unsigned char shifted_mask = mask << (3-front_gap);
        // &~mask to clean, then | the new 5-bit code in
        ss->array[byte_to_start] = (ss->array[byte_to_start] & ~shifted_mask)
                                   | shifted_squeezed_c;
    }
    
    return;
}

char ss_read(squeezed_string* ss, unsigned int i) {
    // error if the ss array doesn't have an ith character encoded
    if (i >= ss->clen) {
        fprintf(stderr, "error: reading out of bounds\n");
        exit(1);
    }
    
    int bit_to_start = i * 5;
    int byte_to_start = bit_to_start / 8;
    int amount_to_shift = bit_to_start - byte_to_start*8;
    
    unsigned char bit_code;
    unsigned char first_byte_part;
    if (amount_to_shift > 3) {
        // clear out all except desired numbers and then set them to right spot
        // by shifting back and forth
        first_byte_part = ss->array[byte_to_start] << amount_to_shift;
        first_byte_part = first_byte_part >> 3;
        // addition works to combine the two parts taken from the bytes
        bit_code = first_byte_part \
                   + (ss->array[byte_to_start+1] >> ((8-amount_to_shift)+3));
    } else {
        bit_code = ss->array[byte_to_start] << amount_to_shift;
        bit_code = bit_code >> 3;
    }
    
    unsigned char letter_out;
    if (bit_code == 0) {
        letter_out = ' ';
    } else {
        letter_out = (unsigned char) (bit_code + 64);
    }
    
    return letter_out;
}

squeezed_string* squeeze(char* s) {
    squeezed_string* ss_out = malloc(sizeof(squeezed_string));
    unsigned int bytes_needed = ceil((double) (strlen(s) * 5) / 8);
    ss_out->array = malloc(bytes_needed * sizeof(unsigned char));
    int i_init;
    for (i_init = 0; i_init < bytes_needed; i_init++) {
        ss_out->array[i_init] = 0;
    }
    ss_out->alen = bytes_needed;
    ss_out->clen = strlen(s);
    
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        ss_write(ss_out, i, s[i]);
    }
    
    return ss_out;
}

char* unsqueeze(squeezed_string* ss) {
    char* s_out = malloc((ss->clen+1) * sizeof(char));
    
    int i;
    for (i = 0; i < ss->clen; i++) {
        s_out[i] = ss_read(ss, i);
    }
    s_out[i] = '\0';
    
    return s_out;
}