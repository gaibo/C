/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 2 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

int main(int argc, char *argv[])
{
    unsigned int n = atoi(argv[1]);
    printf("%u\n", sum_cubes(n));
    return 0;
}