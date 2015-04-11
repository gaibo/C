/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 2 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

int main(int argc, char *argv[])
{
    unsigned int rungs = atoi(argv[1]);
    unsigned int width = atoi(argv[2]);
    unsigned int between = atoi(argv[3]);
    ladder(rungs, width, between);
    return 0;
}