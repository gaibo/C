/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 3 */

#include <stdio.h>
#include <stdlib.h>
#include "hw3.h"


int main(int argc, char *argv[]) {
    int alen = atoi(argv[1]);
    int* a = malloc(alen * sizeof(int));
    
    printf("enter the integers of the array one at a time, " \
        "separated by spaces\n");
    int counter;
    for (counter = 0; counter < alen; counter++) {
        scanf("%d", &a[counter]);
    }
    
    if (millionaire(a, alen)) {
        printf("yes");
    } else {
        printf("no");
    }
    
    free(a);
    return 0;
}