/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 3 */

#include <stdio.h>
#include <stdlib.h>
#include "hw3.h"


/**** Problem 1 ****/

void evidence_sum(void) {
    printf("*** testing sum\n");
    int array_1[] = {1, 2, 3, 4};
    int array_2[] = {1, 2, 3};
    printf("sum(array_1, 4) - expecting 10: %d\n", sum(array_1, 4));
    printf("sum(array_2, 3) - expecting 6: %d\n", sum(array_2, 3));
    return;
}

void evidence_squares(void) {
    printf("*** testing squares\n");
    int* array_1 = malloc(4*sizeof(int));
    int i;
    for (i = 0; i < 4; i++) {
        array_1[i] = i;
    }
    squares(array_1, 4);
    printf("0:\t%d\n", array_1[0]);
    printf("1:\t%d\n", array_1[1]);
    printf("2:\t%d\n", array_1[2]);
    printf("3:\t%d\n", array_1[3]);
    free(array_1);
    return;
}

void evidence_positives(void) {
    printf("*** testing positives\n");
    int* array_1 = malloc(5*sizeof(int));
    array_1[0] = 1;
    array_1[1] = 2;
    array_1[2] = -3;
    array_1[3] = -4;
    array_1[4] = 5;
    int* array_1_length = malloc(sizeof(int));
    *array_1_length = 5;
    positives(array_1, array_1_length);
    printf("new array elements:\n");
    printf("expected: {1, 2, 5}\n");
    int i;
    for (i = 0; i < *array_1_length; i++) {
        printf("position %d:\t%d\n", i, array_1[i]);
    }
    free(array_1);
    free(array_1_length);
    return;
}

void evidence_millionaire(void) {
    printf("*** testing millionaire\n");
    int array_1[] = {1E5, 5E5, 4E5, 0, 0};
    int array_2[] = {1E5, 5E5, 3E5, 500, 0};
    printf("millionaire(array_1, 5) - expecting 1: %d\n", \
        millionaire(array_1, 5));
    printf("millionaire(array_2, 5) - expecting 0: %d\n", \
        millionaire(array_2, 5));
    return;
}


/**** Problem 2 ****/

void evidence_base_to_int(void) {
    printf("*** testing base_to_int\n");
    int digits1[] = {5, 4, 3, 2};
    int digits2[] = {7, 6, 5};
    printf("base_to_int(4, digits1, 10) - expecting 5432: %d\n",
        base_to_int(4, digits1, 10));
    printf("base_to_int(3, digits2, 8) - expecting 501: %d\n",
        base_to_int(3, digits2, 8));
    return;
}

void evidence_hex_str_to_int_arr(void) {
    printf("*** testing hex_str_to_int_arr\n");
    int* int_arr_1 = hex_str_to_int_arr("0X12F42", 7);
    printf("hex_str_to_int_arr(\"0X12F42\",7):\n");
    printf("%d\n", int_arr_1[0]);
    printf("%d\n", int_arr_1[1]);
    printf("%d\n", int_arr_1[2]);
    printf("%d\n", int_arr_1[3]);
    printf("%d\n", int_arr_1[4]);
    printf("converted %d\n", base_to_int(7-2, int_arr_1, 16));
    free(int_arr_1);
    return;
}

void evidence_oct_str_to_int_arr(void) {
    printf("*** testing oct_str_to_int_arr\n");
    int* int_arr_1 = oct_str_to_int_arr("01242", 5);
    printf("oct_str_to_int_arr(\"01242\",5):\n");
    printf("%d\n", int_arr_1[0]);
    printf("%d\n", int_arr_1[1]);
    printf("%d\n", int_arr_1[2]);
    printf("%d\n", int_arr_1[3]);
    printf("converted %d\n", base_to_int(5-1, int_arr_1, 8));
    free(int_arr_1);
    return;
}

void evidence_dec_str_to_int_arr(void) {
    printf("*** testing dec_str_to_int_arr\n");
    int* int_arr_1 = dec_str_to_int_arr("1242",4);
    printf("dec_str_to_int_arr(\"1242\",4):\n");
    printf("%d\n", int_arr_1[0]);
    printf("%d\n", int_arr_1[1]);
    printf("%d\n", int_arr_1[2]);
    printf("%d\n", int_arr_1[3]);
    printf("converted %d\n", base_to_int(4, int_arr_1, 10));
    free(int_arr_1);
    return;
}

void evidence_str_to_int(void) {
    printf("*** testing str_to_int\n");
    printf("str_to_int(\"1242\") - expecting 1242: %d\n", \
        str_to_int("1242"));
    printf("str_to_int(\"-1242\") - expecting -1242: %d\n", \
        str_to_int("-1242"));
    printf("str_to_int(\"01242\") - expecting 674: %d\n", \
        str_to_int("01242"));
    printf("str_to_int(\"0x1242\") - expecting 4674: %d\n", \
        str_to_int("0x1242"));
    printf("str_to_int(\"0X12F42\") - expecting 77634: %d\n", \
        str_to_int("0X12F42"));
    return;
}


/**** Problem 3 ****/

void evidence_str_match(void) {
    printf("*** testing str_match\n");
    printf("str_match(\"Hello\", \"Hello\", 5) - expecting 1: %d\n", \
        str_match("Hello", "Hello", 5));
    printf("str_match(\"Hello\", \"Hellp\", 4) - expecting 1: %d\n", \
        str_match("Hello", "Hellp", 4));
    printf("str_match(\"Hello\", \"hellp\", 4) - expecting 0: %d\n", \
        str_match("Hello", "hellp", 4));
    return;
}

void evidence_find_replace(void) {
    printf("*** testing find_replace\n");
    char* dest = malloc(12 * sizeof(char));
    printf("expecting: hi world\n");
    find_replace("hello world", "hello", "hi", dest);
    puts(dest);
    printf("expecting: hello world\n");
    find_replace("hello world", "hallo", "hi", dest);
    puts(dest);
    printf("expecting: barbarbar\n");
    find_replace("foofoofoo", "foo", "bar", dest);
    puts(dest);
    printf("expecting:  thing is re, n?\n");
    find_replace("the thing is there, then?", "the", "", dest);
    puts(dest);
    free(dest);
    return;
}

/*****************************************************************************/

int main() {
    evidence_sum();
    printf("\n");
    evidence_squares();
    printf("\n");
    evidence_positives();
    printf("\n");
    evidence_millionaire();
    printf("\n");
    evidence_base_to_int();
    printf("\n");
    evidence_hex_str_to_int_arr();
    printf("\n");
    evidence_oct_str_to_int_arr();
    printf("\n");
    evidence_dec_str_to_int_arr();
    printf("\n");
    evidence_str_to_int();
    printf("\n");
    evidence_str_match();
    printf("\n");
    evidence_find_replace();
    return 0;
}