#ifndef _HTBL_H
#define _HTBL_H

#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* hash table of strings, with linked list buckets */
struct hash_table {
    unsigned long int(*hash)(char*);
    unsigned int n_buckets;
    sll** buckets;  /* an array of pointers to string lists */
};
typedef struct hash_table htbl;

/* good_hash : (char*) -> unsigned long int */
/* compute hash code for given string using a chosen algorithm */
unsigned long int good_hash(char* s);

/* bad_hash : (char*) -> unsigned long int */
/* compute an unsophisticated hash for testing purposes */
unsigned long int bad_hash(char* s);

/* ht_new : ((char* -> unsigned long int) unsigned int) -> htbl* */
/* allocate space for a new hash table of given size */
/* NOTE: all buckets must initially contain the empty list */
htbl* ht_new(unsigned long int(*h)(char*), unsigned int sz);

/* ht_n_entries : (htbl*) -> unsigned int */
/* return the total number of entries in all buckets */
unsigned int ht_n_entries(htbl* t);

/* ht_load_factor : (htbl*) -> double */
/* compute the mean number of elements per bucket */
double ht_load_factor(htbl* t);

/* ht_max_bucket : (htbl*) -> unsigned int */
/* report the number of items in the fullest bucket */
// ideally, the max bucket has 1 item in it
unsigned int ht_max_bucket(htbl* t);

/* ht_ins : (char*, htbl*) -> unsigned int */ 
/* insert a string into a hash table and */
/* return the number of strings in the chosen bucket */
/* NOTE: no special treatment for duplicates, just insert them again */
unsigned int ht_ins(char* s, htbl* t);

/* ht_ins_list : (string_list*, htbl*) -> <void> */ 
/* insert a list of strings to a hash table */
void ht_ins_list(sll* ss, htbl* t);

/* ht_member : (char*, htbl*) -> int */
/* test membership of given string in given table */
int ht_member(char* s, htbl* t);

/* ht_show : (htbl*) -> <void> */
/* print a representation of the hash table to stdout */
void ht_show(htbl* t);

/* ht_free : (htbl*) -> <void> */
/* free the hash table */
void ht_free(htbl* t);

/* is_prime : (unsigned int) -> int */
/* test whether a number is prime */
int is_prime(unsigned int number);

/* next_prime : (unsigned int current) -> unsigned int */
/* return the next prime number */
unsigned int next_prime(unsigned int current);

/* previous_prime : (unsigned int current) -> unsigned int */
/* return the previous prime number */
unsigned int previous_prime(unsigned int current);

/* ht_resize : (htbl**) -> <void> */
/* resize a hash table so that its load factor falls between 0.8 and 1.2 */
/* NOTE: doesn't modify an empty table */
void ht_resize(htbl** t);

#endif /* _HTBL_H */