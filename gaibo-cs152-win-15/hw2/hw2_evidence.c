/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 2 */


#include <stdio.h>
#include "hw2.h"


/**** Problem 1 ****/

void evidence_sum_cubes(void) {
    printf("*** testing sum_cubes\n");
    printf("sum_cubes(4) - expecting 100: %u\n", sum_cubes(4));
    printf("sum_cubes(1) - expecting 1: %u\n", sum_cubes(1));
    printf("sum_cubes(0) - expecting 0: %u\n", sum_cubes(0));
}


/**** Problem 2 ****/

void evidence_between_space_maker(void) {
    printf("*** testing between_space_maker\n");
    printf("between_space_maker(3, 2)\n");
    between_space_maker(3, 2);
    printf("between_space_maker(4, 4)\n");
    between_space_maker(4, 4);
}

void evidence_rung_maker(void) {
    printf("*** testing rung_maker\n");
    printf("rung_maker(3)\n");
    rung_maker(3);
    printf("rung_maker(4)\n");
    rung_maker(4);
}

void evidence_ladder(void) {
    printf("*** testing ladder\n");
    printf("ladder(5, 3, 2)\n");
    ladder(5, 3, 2);
    printf("ladder(4, 4, 4)\n");
    ladder(4, 4, 4);
    printf("ladder(0, 4, 4)\n");
    ladder(0, 4, 4);
}


/**** Problem 3 ****/

void evidence_stairs(void) {
    printf("*** testing stairs\n");
    printf("stairs(5, 3, 2)\n");
    stairs(5, 3, 2);
    printf("stairs(4, 4, 4)\n");
    stairs(4, 4, 4);
    printf("stairs(0, 4, 4)\n");
    stairs(0, 4, 4);
}


/**** Problem 4 ****/

void evidence_base_to_int(void) {
    printf("*** testing base_to_int\n");
    int digits1[] = {2, 3, 4, 5};
    int digits2[] = {5, 6, 7};
    printf("base_to_int(4, digits1, 10) - expecting 5432: %d\n",
        base_to_int(4, digits1, 10));
    printf("base_to_int(3, digits2, 8) - expecting 501: %d\n",
        base_to_int(3, digits2, 8));
}


/*****************************************************************************/


int main()
{
    evidence_sum_cubes();
    printf("\n");
    evidence_between_space_maker();
    printf("\n");
    evidence_rung_maker();
    printf("\n");
    evidence_ladder();
    printf("\n");
    evidence_stairs();
    printf("\n");
    evidence_base_to_int();
    return 0;
}