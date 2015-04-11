/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 6 */

#ifndef _SS_H
#define _SS_H

typedef struct squeezed_string squeezed_string;
struct squeezed_string {
    unsigned char* array;
    unsigned int alen;  // elements in array
    unsigned int clen;  // characters in string represented
};

/* squeezed_string* [unsigned int] char -> void */
/* write an encoded 5-bit character into a squeezed_string */
void ss_write(squeezed_string* ss, unsigned int i, char c);

/* squeezed_string* [unsigned int] -> char */
/* read a char from a squeezed_string */
char ss_read(squeezed_string* ss, unsigned int i);

/* char* -> squeezed_string* */
/* convert a string into a squeezed_string */
squeezed_string* squeeze(char* s);

/* squeezed_string* -> char* */
/* convert a squeezed_string into a string */
char* unsqueeze(squeezed_string* ss);

#endif /* _SS_H */