/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 1 */

#include <stdlib.h>
#include <stdio.h>
#include "expt.h"

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);          /* reads 1st command line argument */
    unsigned int n = atoi(argv[2]); /* reads 2nd command line argument */
    printf("%ld\n",ss(a,n));
    return 0;
}
