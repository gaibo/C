/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 3 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/**** Problem 1 ****/

int sum(int* a, int alen) {
    int acc = 0;
    int i;
    for (i = 0; i < alen; i++) {
        acc += a[i];
    }
    return acc;
}

void squares(int* a, int alen) {
    int i;
    for (i = 0; i < alen; i++) {
        a[i] *= a[i];
    }
    return;
}

void positives(int* a, int* alen) {
    int input_i = 0;
    int positive_i = 0;
    
    while (input_i < *alen) {
        if (a[input_i] > 0) {   // if positive, set to itself
            a[positive_i] = a[input_i];
            input_i++;
            positive_i++;
        } else {    // if not, allow position to be set to the next positive
            input_i++;
        }
    }
    
    *alen = positive_i;
    
    return;
}

int millionaire(int* a, int alen) {
    int acc = 0;
    int i;
    for (i = 0; i < alen; i++) {
        acc += a[i];
        if (acc >= 1E6) {
            return 1;
        }
    }
    return 0;
}


/**** Problem 2 ****/

/*
int strlen(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}
*/

// modified version of the one from hw2 so that it doesn't read backwards
int base_to_int(int ndigits, int* digits, int base) {
    int acc = 0;
    int digit_counter = 0;
    int pow_counter = ndigits-1;
    while (digit_counter < ndigits) {
        acc += digits[digit_counter] * pow(base, pow_counter);
        digit_counter++;
        pow_counter--;
    }
    return acc;
}

int* hex_str_to_int_arr(char* hex_str, int str_len) {
    // allocate less since the first two and null character are not copied
    int* int_arr = malloc((str_len-2) * sizeof(int));
    int i;
    for (i = 2; hex_str[i] != '\0'; i++) {
        if ((hex_str[i] == 'a') || (hex_str[i] == 'A')) {
            int_arr[i-2] = 10;
        } else if ((hex_str[i] == 'b') || (hex_str[i] == 'B')) {
            int_arr[i-2] = 11;
        } else if ((hex_str[i] == 'c') || (hex_str[i] == 'C')) {
            int_arr[i-2] = 12;
        } else if ((hex_str[i] == 'd') || (hex_str[i] == 'D')) {
            int_arr[i-2] = 13;
        } else if ((hex_str[i] == 'e') || (hex_str[i] == 'E')) {
            int_arr[i-2] = 14;
        } else if ((hex_str[i] == 'f') || (hex_str[i] == 'F')) {
            int_arr[i-2] = 15;
        } else {
            int_arr[i-2] = hex_str[i] - 48; // handy ascii math for char->int
        }
    }
    return int_arr;
}

int* oct_str_to_int_arr(char* oct_str, int str_len) {
    // allocate less since the first and null character are not copied
    int* int_arr = malloc((str_len-1) * sizeof(int));
    int i;
    for (i = 1; oct_str[i] != '\0'; i++) {
        int_arr[i-1] = oct_str[i] - 48;
    }
    return int_arr;
}

int* dec_str_to_int_arr(char* dec_str, int str_len) {
    // allocate less since null character is not copied
    // note: space for the optional '-' character at the beginning
    //      is allocated; extra space can remain at end of array
    int* int_arr = malloc((str_len) * sizeof(int));
    int i;
    if (dec_str[0] == '-') {
        // accounting for '-' although not returning it
        // note: parent function must add the negative back
        for (i = 1; dec_str[i] != '\0'; i++) {
            int_arr[i-1] = dec_str[i] - 48;
        }
    } else {
        for (i = 0; dec_str[i] != '\0'; i++) {
            int_arr[i] = dec_str[i] - 48;
        }
    }
    return int_arr;
}

int str_to_int(char* str) {
    int str_len = strlen(str);
    int* int_arr;
    int answer;
    
    if (str[0] == '0') {
        if ((str[1] == 'x') || (str[1] == 'X')) {
            // hexadecimal case
            int_arr = hex_str_to_int_arr(str, str_len);
            answer = base_to_int(str_len-2, int_arr, 16);
        } else {
            // octal case
            int_arr = oct_str_to_int_arr(str, str_len);
            answer = base_to_int(str_len-1, int_arr, 8);
        }
    } else if (str[0] == '-') {
        // negative decimal case
        int_arr = dec_str_to_int_arr(str, str_len);
        answer = -1 * base_to_int(str_len-1, int_arr, 10);  // adding back '-'
    } else {
        // positive decimal case
        int_arr = dec_str_to_int_arr(str, str_len);
        answer = base_to_int(str_len, int_arr, 10);
    }
    
    free(int_arr);
    return answer;
}


/**** Problem 3 ****/

int str_match(char* str_1, char* str_2, int match_len) {
    int i;
    for (i = 0; i < match_len; i++) {
        if (str_1[i] != str_2[i]) {
            return 0;
        }
    }
    return 1;
}

void find_replace(char* src, char* from, char* to, char* dest) {
    int src_len = strlen(src);
    int from_len = strlen(from);
    int to_len = strlen(to);
    // error checking
    if (to_len > from_len) {
        fprintf(stderr, "error, 'to' is longer than 'from'\n");
        return;
    }
    int i_src;
    int i_from;
    int i_dest;
    
    for (i_src = 0, i_dest = 0; i_src <= src_len; i_src++, i_dest++) {
        if (str_match(&src[i_src], from, from_len)) {
            for (i_from = i_src; i_from-i_src < to_len; i_from++) {
                dest[i_from] = to[i_from-i_src];
            }
            i_src += from_len-1;
            i_dest += to_len-1;
        } else {
            dest[i_dest] = src[i_src];
        }
    }
    
    return;
}