/* Gaibo Zhang, gaibo */
/* CS 152, Winter 2015 */
/* Homework 2 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hw2.h"


/**** Problem 1 ****/

unsigned int sum_cubes(unsigned int n) {
    unsigned int acc = 0;
    unsigned int i;
    for (i = 1; i <= n; i++) {
        acc += i*i*i;
    }
    return acc;
}


/**** Problem 2 ****/

void between_space_maker(unsigned int width, unsigned int between) {
    unsigned int i_between;
    unsigned int i_width;
    for (i_between = 1; i_between <= between; i_between++) {
        printf("*");
        for (i_width = 1; i_width <= width; i_width++) {
            printf(" ");
        }
        printf("*\n");
    }
}

void rung_maker(unsigned int width) {
    unsigned int i_width;
    printf("*");
    for (i_width = 1; i_width <= width; i_width++) {
        printf("*");
    }
    printf("*\n");
}

void ladder(unsigned int rungs, unsigned int width, unsigned int between) {
    // error/special case handling
    if ((width == 0) || (between == 0)) {
        fprintf(stderr, "width and between must be positive");
        exit(1);
    }
    if (rungs == 0) {
        printf("\n");
        exit(0);
    }
    
    unsigned int i_rungs;
    // creating the top of the ladder
    between_space_maker(width, between);
    // creating the rest of the ladder with rungs and space
    for (i_rungs = 1; i_rungs <= rungs; i_rungs++) {
        rung_maker(width);
        between_space_maker(width, between);
    }
}


/**** Problem 3 ****/

void stairs(unsigned int steps, unsigned int depth, unsigned int riser) {
    // error/special case handling
    if ((depth == 0) || (riser == 0)) {
        fprintf(stderr, "depth and riser must be positive");
        exit(1);
    }
    if (steps == 0) {
        printf("\n");
        exit(0);
    }
    
    unsigned int i_steps;
    unsigned int i_riser;
    unsigned int i_depth;
    unsigned int i_stars;
    unsigned int i_periods;
    // loop for making the macro steps
    for (i_steps = 1; i_steps <= steps; i_steps++) {
        // loop for making thickness of the macro steps
        for (i_riser = 1; i_riser <= riser; i_riser++) {
            // loop for making the varying lengths of stars
            for (i_stars = i_steps; i_stars >= 2; i_stars--) {
                // loop for making the basic unit of the stars
                for (i_depth = 1; i_depth <= depth; i_depth++) {
                    printf("*");
                }
            }
            // loop for making the varying lengths of periods
            for (i_periods = i_steps; i_periods <= steps; i_periods++) {
                // loop for making the basic unit of the periods
                for (i_depth = 1; i_depth <= depth; i_depth++) {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}


/**** Problem 4 ****/

int base_to_int(int ndigits, int* digits, int base) {
    int acc = 0;
    int counter;
    for (counter = 0; counter < ndigits; counter++) {
        acc += digits[counter] * pow(base, counter);
    }
    return acc;
}