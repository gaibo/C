/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 5 */


/**** Struct Definitions ****/

typedef struct string_list string_list;    
struct string_list {
    char* val;
    string_list* next;
};


/**** Function Declarations ****/

/* string_list* -> int */
/* determine whether a list is in ascending lexicographic order */
/* note: duplicates are allowed */
int sl_sorted_asc(string_list* ss);

/* char* string_list* -> string_list* */
/* insert the string val into the list in its proper sorted position */
/* note: assumes string_list given is sorted in ascending order */
string_list* sl_insert(char* s, string_list* ss);
string_list* cons_create(char* s, string_list* tl);
void cons_link(string_list* hd, string_list* tl);

/* int string_list* -> string_list* */
/* filter the list destructively according to the test function */
string_list* sl_filter(int (*test)(char*), string_list* ss);