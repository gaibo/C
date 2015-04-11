/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 3 */

#include <stdio.h>
#include <stdlib.h>
#include "hw3.h"


int main(int argc, char *argv[]) {
    char* src = argv[1];
    char* from = argv[2];
    char* to = argv[3];
    char* dest = src;   // to allocate the max length needed
    
    find_replace(src, from, to, dest);
    
    fputs(dest, stdout);
    
    return 0;
}