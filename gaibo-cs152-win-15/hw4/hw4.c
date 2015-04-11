/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "hw4.h"


/**** Problem 1 ****/

char* concat(char** strs, unsigned int nstrs) {
    unsigned int i_str;
    unsigned int i_char;
    
    // running some loops to determine how much memory is needed
    unsigned int str_len_acc;
    
    for (i_str = 0; i_str < nstrs; i_str++) {
        for (i_char = 0; strs[i_str][i_char] != '\0'; i_char++) {
            str_len_acc++;
        }
    }
    
    // allocate precise amount of memory
    char* concat_str = malloc(str_len_acc * sizeof(char));
    
    // putting chars into the concatenation string
    unsigned int i_concat = 0;
    
    for (i_str = 0; i_str < nstrs; i_str++) {
        for (i_char = 0; strs[i_str][i_char] != '\0'; i_char++) {
            concat_str[i_concat] = strs[i_str][i_char];
            i_concat++;
        }
    }
    concat_str[i_concat] = '\0';  // end the string
    
    return concat_str;
}


/**** Problem 2 ****/

char* uint_to_binary(unsigned int n) {
    // length of binary determined with log; plus 1 for 0 exponent offset
    unsigned int bin_len;
    
    if (!n) {   // handling n = 0 case
        bin_len = 1;
    } else {
        bin_len = (unsigned int) log2(n) + 1;
    }
    
    // allocating memory; plus 1 for null character
    char* bin_str = malloc((bin_len+1) * sizeof(char));
    
    // filling in digits with algorithm
    int i;
    
    bin_str[bin_len] = '\0';
    for (i = bin_len-1; i >= 0; i--) {
        if (n%2) {  // odd
            bin_str[i] = '1';
        } else {    // even
            bin_str[i] = '0';
        }
        n /= 2;
    }
    
    return bin_str;
}

unsigned int binary_to_uint(char* b) {
    // find length of binary string
    unsigned int bin_len = strlen(b);
    
    // converting base 2 to base 10
    unsigned int acc = 0;
    unsigned int digit_counter = 0;
    unsigned int pow_counter = bin_len - 1;
    
    while (digit_counter < bin_len) {
        acc += (b[digit_counter] - '0') * pow(2, pow_counter);  // ASCII math
        digit_counter++;
        pow_counter--;
    }
    
    return acc;
}


/**** Problem 3 ****/

void analyze_weather(struct observations* observations,
                     unsigned int nobservations,
                     struct climate* climate,
                     struct preferences* preferences,
                     struct compatibility* compatibility) {
    // initializing values to prepare for collection
    climate->temps.avg = 0;
    climate->temps.min = DBL_MAX;
    climate->temps.max = -DBL_MAX;
    
    climate->humids.avg = 0;
    climate->humids.min = DBL_MAX;
    climate->humids.max = -DBL_MAX;
    
    climate->winds.avg = 0;
    climate->winds.min = DBL_MAX;
    climate->winds.max = -DBL_MAX;
    
    compatibility->good_days = 0;
    compatibility->bad_days = 0;
    compatibility->happiness = 0;
    compatibility->good_data =
        malloc(nobservations * sizeof(struct observations*));
    compatibility->bad_data =
        malloc(nobservations * sizeof(struct observations*));
    
    ////// collecting
    unsigned int i_obs;
    unsigned int i_good_data = 0;
    unsigned int i_bad_data = 0;
    
    for (i_obs = 0; i_obs < nobservations; i_obs++) {
        //// collecting climate stats
        // temps stats
        climate->temps.avg += (observations[i_obs].temp)/nobservations;
        if (observations[i_obs].temp < climate->temps.min) {
            climate->temps.min = observations[i_obs].temp;
        }
        if (observations[i_obs].temp > climate->temps.max) {
            climate->temps.max = observations[i_obs].temp;
        }
        // humids stats
        climate->humids.avg += (observations[i_obs].humid)/nobservations;
        if (observations[i_obs].humid < climate->humids.min) {
            climate->humids.min = observations[i_obs].humid;
        }
        if (observations[i_obs].humid > climate->humids.max) {
            climate->humids.max = observations[i_obs].humid;
        }
        // winds stats
        climate->winds.avg += (observations[i_obs].wind)/nobservations;
        if (observations[i_obs].wind < climate->winds.min) {
            climate->winds.min = observations[i_obs].wind;
        }
        if (observations[i_obs].wind > climate->winds.max) {
            climate->winds.max = observations[i_obs].wind;
        }
        //// collecting compatibility info
        if (observations[i_obs].temp >= preferences->temps.min && \
            observations[i_obs].temp <= preferences->temps.max && \
            observations[i_obs].humid >= preferences->humids.min && \
            observations[i_obs].humid <= preferences->humids.max && \
            observations[i_obs].wind >= preferences->winds.min && \
            observations[i_obs].wind <= preferences->winds.max) {
            compatibility->good_days++;
            compatibility->happiness += (double) 1/nobservations;
            compatibility->good_data[i_good_data] = &observations[i_obs];
            i_good_data++;
        } else {
            compatibility->bad_days++;
            compatibility->bad_data[i_bad_data] = &observations[i_obs];
            i_bad_data++;
        }
    }
    
    return;
}


/**** Problem 4 ****/

unsigned int element_weight(struct element* element) {
    return element->weight;
}

unsigned int molecule_weight(struct molecule* molecule) {
    unsigned int i;
    unsigned int mol_weight_acc = 0;
    for (i = 0; i < molecule->nelements; i++) {
        mol_weight_acc += molecule->elements[i]->weight * molecule->atoms[i];
    }
    return mol_weight_acc;
}

unsigned int mixture_weight(struct mixture* mixture) {
    unsigned int i;
    unsigned int mix_grams_acc = 0;
    
    for (i = 0; i < mixture->nchemicals; i++) {
        if (mixture->chemicals[i].tag == ELEMENT) {
            mix_grams_acc +=
                element_weight(mixture->chemicals[i].chemical.element)
                * mixture->moles[i];
        } else if (mixture->chemicals[i].tag == MOLECULE) {
            mix_grams_acc +=
                molecule_weight(mixture->chemicals[i].chemical.molecule)
                * mixture->moles[i];
        } else {
            fprintf(stderr, "error: chemical neither element nor molecule");
            return 1;
        }
    }
    
    return mix_grams_acc;
}