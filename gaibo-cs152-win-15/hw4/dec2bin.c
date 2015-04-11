/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"

int main(int argc, char* argv[]) {
    unsigned int uint = atoi(argv[1]);
    
    char* bin_str = uint_to_binary(uint);
    puts(bin_str);
    free(bin_str);
    return 0;
}