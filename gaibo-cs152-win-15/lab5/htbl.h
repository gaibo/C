#ifndef _HTBL_H
#define _HTBL_H

#include "sll.h"

/* hash table of strings, with linked list buckets */

struct hash_table {
  unsigned long int(*hash)(char *);
  unsigned int n_buckets;
  sll **buckets; /* an array of pointers to string lists */
};
typedef struct hash_table htbl;

/* good_hash : char -> unsigned int */
/* compute hash code for given string */
/* see web page for algorithm */
unsigned long int good_hash(char *s);

/* bad_hash : char -> unsigned int */
/* implement this however you like, as long as it's bad */
unsigned long int bad_hash(char *s);

/* ht_new : (string -> unsigned long) int -> htbl* */
/* allocate space for a new hash table of given size */
/* all buckets must initially contain the empty list */
htbl *ht_new(unsigned long int(*h)(char*), unsigned int sz);

/* ht_n_entries : htbl* -> unsigned int */
/* return the total number of entries in all buckets */
unsigned int ht_n_entries(htbl *t);

/* ht_load_factor : htbl* -> float */
/* The load factor is the mean number of elements per bucket. */
double ht_load_factor(htbl *t);

/* ht_max_bucket : htbl* -> unsigned int */
/* Report the number of items in the fullest bucket. */
/* (Ideally, the max bucket has 1 item in it.) */
unsigned int ht_max_bucket(htbl *t);

/* ht_ins : (char*, htbl*) -> int */ 
/* add string s to hash table t */
/* no special treatment for duplicates, just insert them again */
/* return the number of strings in s's bucket after inserting it */
unsigned int ht_ins(char *s, htbl *t);

/* ht_ins_list : (string_list*, htbl*) -> int */ 
/* add strings to hash table t */
void ht_ins_list(sll *ss, htbl *t);

/* ht_member : (char*, htbl*) -> int */
/* test membership of given string in given table */
int ht_member(char *s, htbl *t);

/* ht_show : htbl* -> <void> */
/* print a representation of the hash table to stdout */
void ht_show(htbl *t);

/* ht_free : htbl* -> <void> */
void ht_free(htbl *t);

#endif /* _HTBL_H */