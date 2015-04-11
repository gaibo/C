/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 4 */


/**** Problem 1 ****/

/* char** [unsigned int] -> char* */
/* consume an array of strings and the length of the array, return a pointer
 * to a new heap-allocated string concatenation of all strings in array */
char* concat(char** strs, unsigned int nstrs);


/**** Problem 2 ****/

/* [unsigned int] -> char* */
/* convert a number into a binary string */
char* uint_to_binary(unsigned int n);

/* char* -> [unsigned int] */
/* convert a binary string into a number */
unsigned int binary_to_uint(char* b);


/**** Problem 3 ****/

/* data structs */
struct observations {
    double temp;
    double humid;
    double wind;
};

struct range {
    double min, max;
};
struct preferences {
    struct range temps, humids, winds;
};

/* result structs */
struct stats {
    double avg, min, max;
};
struct climate {
    struct stats temps, humids, winds;
};

struct compatibility {
    unsigned int good_days, bad_days;
    double happiness;
    struct observations **good_data, **bad_data;
};

/* [struct observations*] [unsigned int] [struct climate*]
 *      [struct preferences*] [struct compatibility*] -> void */
/* analyze compatibility for weather; all info goes into editing arrays */
void analyze_weather(struct observations* observations,
                     unsigned int nobservations,
                     struct climate* climate,
                     struct preferences* preferences,
                     struct compatibility* compatibility);
                     
                     
/**** Problem 4 ****/

struct element {
    char* name;
    unsigned int weight;
};

struct molecule {
    char* name;
    unsigned int nelements;
    struct element** elements;
    unsigned int* atoms;
    /* there are atoms[i] atoms of element elements[i] */
};

union chemical {
    struct element* element;
    struct molecule* molecule;
};

enum chemical_tag {
    ELEMENT, MOLECULE
};

struct tagged_chemical {
    enum chemical_tag tag;
    union chemical chemical;
};

struct mixture {
    char* name;
    unsigned int nchemicals;
    struct tagged_chemical* chemicals;
    double* moles;
    /* there are moles[i] moles of chemical chemicals[i] */
};

/* [struct element*] -> [unsigned int] */
/* [AUX] return the weight of an element */
unsigned int element_weight(struct element* element);

/* [struct molecule*] -> [unsigned int] */
/* [AUX] return the weight of a molecule */
unsigned int molecule_weight(struct molecule* molecule);

/* [struct mixture*] -> [unsigned int] */
/* given a mixture, determine its weight in grams */
unsigned int mixture_weight(struct mixture* mixture);