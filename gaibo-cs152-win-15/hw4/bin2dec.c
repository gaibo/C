/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"

int main(int argc, char* argv[]) {
    char* bin_str = argv[1];
    
    printf("%u\n", binary_to_uint(bin_str));
    return 0;
}