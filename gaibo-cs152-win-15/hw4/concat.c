/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"

int main(int argc, char* argv[]) {
    unsigned int nstrs = argc - 1;
    // short-circuit if no string arguments
    if (!nstrs) {
        return 0;
    }
    char** strs = malloc(nstrs * sizeof(char*));
    
    int i;
    for (i = 1; i < argc; i++) {
        strs[i-1] = argv[i];
    }
    
    char* concat_str = concat(strs, nstrs);
    puts(concat_str);
    free(concat_str);
    free(strs);
    return 0;
}