/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 3 */


/**** Problem 1 ****/

/* sum : int* int -> int */
/* sum the values in an array of given length */
int sum(int* a, int alen);

/* squares : int* int -> void */
/* square each of the elements in an array of given length and overwrite
 * each element with squared value */
void squares(int* a, int alen);

/* positives : int* int* -> void */
/* filter out non-positive values of an array */
void positives(int* a, int* alen);

/* millionaire : int* int -> int */
/* add up the assets in the array and return true if the sum is at least
 * a million; short-circuits upon reaching a million */
int millionaire(int* a, int alen);


/**** Problem 2 ****/

/** OMITTED **/
/* strlen : char* -> int */
/* determine the length of a string */
// int strlen(char* str);

/* base_to_int : int int* int -> int */
/* given # of digits, array of digits, and base, return the decimal number */
int base_to_int(int ndigits, int* digits, int base);

/* hex_str_to_int_arr : char* int -> int* */
/* convert a hexadecimal string into a decimal int array */
int* hex_str_to_int_arr(char* hex_str, int str_len);

/* oct_str_to_int_arr : char* int -> int* */
/* convert an octal string into a decimal int array */
int* oct_str_to_int_arr(char* oct_str, int str_len);

/* dec_str_to_int_arr : char* int -> int* */
/* convert a decimal string into a decimal int array */
int* dec_str_to_int_arr(char* dec_str, int str_len);

/* str_to_int : char* -> int */
/* take a string of a number in decimal, octal, or hexadecimal form
 * and output its decimal value */
int str_to_int(char* str);


/**** Problem 3 ****/

/* str_match : char* char* int -> int (pseudo-Boolean) */
/* given two strings and a length, return true if the strings match
 * for the specified length */
int str_match(char* str_1, char* str_2, int match_len);

/* find_replace : char* char* char* char* -> void */
/* find and replace "from" with "to" as "src" is copied to "dest" */
void find_replace(char* src, char* from, char* to, char* dest);