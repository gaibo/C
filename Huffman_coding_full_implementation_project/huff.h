/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 6 */


#ifndef HUFF_H
#define HUFF_H

typedef struct leaf leaf;
typedef struct node node;
typedef struct huff huff;

enum huff_tag { LEAF, NODE };

struct leaf {
  char c;
  int n;
};

struct node {
  int n;
  huff* lsub;
  huff* rsub;
};

union huff_union {
  leaf leaf;
  node node;
};

struct huff {
  enum huff_tag tag;
  union huff_union h;
};

typedef struct huff_list huff_list;
struct huff_list {
    huff* huff;
    huff_list* next;
};

/* Here follow prototypes for a selection of functions you will likely
   want. You will need to write more, but this is a start.
 */ 

/* Construct a singleton Huffman tree from a character and a count. */
huff* huff_singleton(char c, int n);

/* Return the weight of a Huffman tree. */
int huff_weight(huff* h);

/* Merge two Huffman trees. */
/* See step 2 of the algorithm on the web page for details. */
huff* huff_merge(huff* h1, huff* h2);

/* Display a Huffman tree at the console. */
/* Essential for development and debugging. */
void huff_show(huff* h);
void huff_show_helper(huff* h, int tabs);

/* count the occurrence of each letter by produce an int array
 * of counts for each of the 26 letters and the space character */
int* occurrences(char* str);

/* using the very contrived occurrences int array, produce an unsorted
 * huff_list */
huff_list* huff_list_builder(int* occ_array);

/* apply insertion sort to the huff_list */
huff_list* insertion_sort(huff_list* unsorted);
huff_list* cons(huff_list* hd, huff_list* tl);
huff_list* hl_insert(huff_list* list_node, huff_list* list);
huff_list* insertion_acc(huff_list* unsorted, huff_list* sorted);

/* run the algorithm for coalescing the huff_list */
huff_list* algorithm(huff_list* sorted);

/* find the number of letters that were encoded by finding the 
 * height of the huff_tree */
unsigned int huff_height(huff* huff);
unsigned int my_max(unsigned int a, unsigned int b);

/* print the huffman codes with this janky printer */
void key_printer(huff* huff, FILE* file);
void key_printer_helper(huff* huff, FILE* file, \
                            char* bin_str_acc, unsigned int end_place);
                           
/* given a letter and the huff tree, return the binary string code */
char* code_generator(char letter, huff* huff);
void code_generator_helper(char letter, huff* huff, char* bin_str_acc);

/* create a full converted string */
char* str_to_code(char* input_str, huff* huff);

/* create a char (byte) array (NOT A STRING) that is final compressed result */
unsigned char* bin_str_to_bits(char* bin_str);

#endif /* HUFF_H */