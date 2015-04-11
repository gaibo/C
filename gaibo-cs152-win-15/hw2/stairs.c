/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 2 */

#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

int main(int argc, char *argv[])
{
    unsigned int steps = atoi(argv[1]);
    unsigned int depth = atoi(argv[2]);
    unsigned int riser = atoi(argv[3]);
    stairs(steps, depth, riser);
    return 0;
}