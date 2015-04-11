/* Gaibo Zhang, gaibo */
/* CS152, Winter 2014 */
/* Homework 1 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/** Function Prototypes **/

/* function: find the greatest common divisor of two natural numbers */
unsigned int gcd(unsigned int a, unsigned int b);

/* function: find the surface area of a sphere given the radius */
double area_sphere(double radius);

/* function: determine the early termination fee given a number of days */
int early_term_fee(int days);

/* helper function: given a phone number and a position, return the digit */
int dig_lookup(long long int number, int position);

/* function: determine whether a number is a valid telephone number */
int is_valid_tel_num(long long int number);


int main() {
    // gcd tests
    printf("gcd test 1: gcd(123, 3). answer: 3. we get: %d\n", gcd(123, 3));
    printf("gcd test 2: gcd(3, 123). answer: 3. we get: %d\n", gcd(3, 123));
    printf("gcd test 3: gcd(123, 0). answer: 123. we get: %d\n", gcd(123, 0));
    printf("gcd test 4: gcd(0, 44). answer: 44. we get: %d\n", gcd(0, 44));
    // area_sphere tests
    printf("area_sphere test 1: area_sphere(1). answer: 4pi, 12.566. " \
        "we get: %lf\n", area_sphere(1));
    printf("area_sphere test 2: area_sphere(2.6). answer: 84.949. " \
        "we get: %lf\n", area_sphere(2.6));
    // early_term_fee tests
    printf("early_term_fee test 1: early_term_fee(10). answer: 0. " \
        "we get: %d\n", early_term_fee(10));
    printf("early_term_fee test 2: early_term_fee(14). answer: 0. " \
        "we get: %d\n", early_term_fee(14));
    printf("early_term_fee test 3: early_term_fee(29). answer: 325. " \
        "we get: %d\n", early_term_fee(29));
    printf("early_term_fee test 4: early_term_fee(719). answer: 95. " \
        "we get: %d\n", early_term_fee(719));
    // dig_lookup tests
    printf("dig_lookup test 1: dig_lookup(7735550199, 1). answer: 7. " \
        "we get: %d\n", dig_lookup(7735550199, 1));
    printf("dig_lookup test 2: dig_lookup(7735550199, 2). answer: 7. " \
        "we get: %d\n", dig_lookup(7735550199, 2));
    printf("dig_lookup test 3: dig_lookup(7735550199, 3). answer: 3. " \
        "we get: %d\n", dig_lookup(7735550199, 3));
    printf("dig_lookup test 4: dig_lookup(7735550199, 10). answer: 9. " \
        "we get: %d\n", dig_lookup(7735550199, 10));
    // is_valid_tel_num tests
    printf("is_valid_tel_num test 1: is_valid_tel_num(7035550199). answer: 1. " \
        "we get: %d\n", is_valid_tel_num(7035550199));
    printf("is_valid_tel_num test 2: is_valid_tel_num(1000000000). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(1000000000));
    printf("is_valid_tel_num test 3: is_valid_tel_num(10000000000). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(10000000000));
    printf("is_valid_tel_num test 4: is_valid_tel_num(1). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(1));
    printf("is_valid_tel_num test 5: is_valid_tel_num(9199999999). answer: 1. " \
        "we get: %d\n", is_valid_tel_num(9199999999));
    printf("is_valid_tel_num test 6: is_valid_tel_num(1199999999). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(1199999999));
    printf("is_valid_tel_num test 7: is_valid_tel_num(9299999999). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(9299999999));
    printf("is_valid_tel_num test 8: is_valid_tel_num(9191999999). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(9191999999));
    printf("is_valid_tel_num test 9: is_valid_tel_num(9199199999). answer: 0. " \
        "we get: %d\n", is_valid_tel_num(9199199999));
}


/** Function Definitions **/

unsigned int gcd(unsigned int a, unsigned int b) {
    // swap number order if necessary so that the first is greater (or equal)
    if (a < b) {
		return gcd(b, a);
    }
    // execute Euler's algorithm on loop
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
	}
}

double area_sphere(double radius) {
    return 4 * M_PI * (radius*radius);
}

int early_term_fee(int days) {
    if ((days <= 14) || (days >= 720)) {
        return 0;
    } else {
        return 325 - (10 * (days/30));
    }
}

int dig_lookup(long long int number, int position) {
    // algorithm that uses modulus and rounding to return the desired digit
    return (number % (long long int) pow(10, 11 - position)) / (long long int) pow(10, 10 - position);
}

int is_valid_tel_num(long long int number) {
    // first check to make sure there is the right number of digits: 10
    // as an integer, that would be order of magnitude of 10^9
    if ((number < pow(10, 9)) || (number >= pow(10, 10))) {
        return 0;
    }
    
    // assign the digits to check
    int first_dig_area = dig_lookup(number, 1);
    int second_dig_area = dig_lookup(number, 2);
    int first_dig_ex = dig_lookup(number, 4);
    int second_dig_ex = dig_lookup(number, 5);
    
    // restrictions to check
    if ((first_dig_area < 2) || (first_dig_area > 9) ||
        ((second_dig_area != 0) && (second_dig_area != 1)) ||
        (first_dig_ex < 2) || (first_dig_ex > 9) ||
        (second_dig_ex < 2) || (second_dig_ex > 9)) {
            return 0;
        } else {
            return 1;
        }
}