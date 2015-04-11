/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 2 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

int main(int argc, char *argv[])
{
    int base = atoi(argv[1]);
    int ndigits = atoi(argv[2]);
    int* digits = malloc(ndigits * sizeof(int));
    printf("enter the digits separated by spaces\n" \
        "(most-significant to least-significant)\n");
    int counter;
    for (counter = ndigits-1; counter >= 0; counter--) {
        scanf("%d", &digits[counter]);
    }
    printf("%d\n", base_to_int(ndigits, digits, base));
    free(digits);
    return 0;
}