#ifndef _SLL_H
#define _SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* linked lists of strings */
typedef struct sll sll;
struct sll {
    char* s;
    sll* next;
};
/* by convention, the empty list is NULL */

/* sll_cons : (char*, sll*) -> sll* */
/* build a new list with given string at the head */
/* NOTE: deep copy the string to the list */
sll* sll_cons(char* s, sll* ss);

/* sll_length : (sll*) -> int */
/* return the number of strings in the given list */
unsigned int sll_length(sll* ss);

/* sll_member : (char*, sll*) -> int */
/* test membership of given string in given list */
/* NOTE: use strcmp to compare strings */
int sll_member(char* s, sll* ss);

/* sll_show : (sll*) -> <void> */
/* print a representation of the linked list to stdout */
void sll_show(sll* ss);

/* sll_free : (sll*) -> <void> */
/* free all strings pointed to */
void sll_free(sll* ss);

#endif /* _SLL_H */