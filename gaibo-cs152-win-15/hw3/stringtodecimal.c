/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 3 */

#include <stdio.h>
#include <stdlib.h>
#include "hw3.h"


int main(int argc, char *argv[]) {
    char* str = argv[1];
    
    printf("%d", str_to_int(str));
    
    return 0;
}