/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 1 */

#include "expt.h"

/* exponentiation by recursion */
long int expt(int a, unsigned int n) {
    if (n == 0) {
        return 1;
    }
    return a * expt(a, (n-1));
}

/* fast exponentiation by successive squaring */
long int ss(int a, unsigned int n) {
    if (n == 0) {
        return 1;
    } else if (n%2) {   // odd case
        return a * ss(a, (n-1));
    } else {    // even case
        return ss(a, (n/2)) * ss(a, (n/2));
    }
}

/* fast exponentiation modulo m */
int ssm(int a, unsigned int n, unsigned int m) {
    if (n == 0) {
        return 1;
    } else if (n%2) {   // odd case
        return a * ssm(a, (n-1), m) % m;
    } else {    // even case
        return ssm(a,(n/2), m) * ssm(a, (n/2), m) % m;
    }
}