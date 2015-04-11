/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 2 */


/**** Problem 1 ****/

/* sum_cubes : [unsigned int] -> [unsigned int] */
/* return the sum of the first n cubes */
unsigned int sum_cubes(unsigned int n);


/**** Problem 2 ****/

/* between_space_maker : [unsigned int] [unsigned int] -> [void] */
/* [AUX] create the space between rungs on a ladder given width
 * and the length between rungs */
void between_space_maker(unsigned int width, unsigned int between);

/* rung_maker : [unsigned int] -> [void] */
/* [AUX] create the rungs on a ladder given a width */
void rung_maker(unsigned int width);

/* ladder : [unsigned int] [unsigned int] [unsigned int] -> [void] */
/* create a ladder given # of rungs, width, and length between rungs */
void ladder(unsigned int rungs, unsigned int width, unsigned int between);


/**** Problem 3 ****/

/* stairs : [unsigned int] [unsigned int] [unsigned int] -> [void] */
/* create stairs given # of steps, extension length of each stair (depth),
 * and amount of rise per step (riser) */
void stairs(unsigned int steps, unsigned int depth, unsigned int riser);


/**** Problem 4 ****/

/* base_to_int : [int] [int*] [int] -> [int] */
/* return a number in base 10 given the number of digits, an array containing
 * the digits from least valuable to greatest, and the base */
int base_to_int(int ndigits, int* digits, int base);