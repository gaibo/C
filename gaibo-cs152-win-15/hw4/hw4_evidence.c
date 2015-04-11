/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 4 */

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"


/**** Problem 1 ****/

void evidence_concat(void) {
    printf("*** testing concat\n");
    char* str_1 = "hello";
    char* str_2 = ",";
    char* str_3 = " ";
    char* str_4 = "world";
    char* str_5 = "!";
    char* strs[] = {str_1, str_2, str_3, str_4, str_5};
    char* concatted_str = concat(strs, 5);
    printf("should get \"hello, world!\":\n");
    puts(concatted_str);
    free(concatted_str);
    return;
}


/**** Problem 2 ****/

void evidence_uint_to_binary(void) {
    printf("*** testing uint_to_binary\n");
    char* bin_str1 = uint_to_binary(0);
    char* bin_str2 = uint_to_binary(1);
    char* bin_str3 = uint_to_binary(5);
    char* bin_str4 = uint_to_binary(31);
    printf("uint_to_binary(0) - expecting \"0\": %s\n", bin_str1);
    printf("uint_to_binary(1) - expecting \"1\": %s\n", bin_str2);
    printf("uint_to_binary(5) - expecting \"101\": %s\n", bin_str3);
    printf("uint_to_binary(31) - expecting \"11111\": %s\n", bin_str4);
    free(bin_str1);
    free(bin_str2);
    free(bin_str3);
    free(bin_str4);
    return;
}

void evidence_binary_to_uint(void) {
    printf("*** testing binary_to_uint\n");
    printf("binary_to_uint(\"0\") - expecting 0: %u\n", binary_to_uint("0"));
    printf("binary_to_uint(\"1\") - expecting 1: %u\n", binary_to_uint("1"));
    printf("binary_to_uint(\"101\") - expecting 5: %u\n", \
        binary_to_uint("101"));
    printf("binary_to_uint(\"11111\") - expecting 31: %u\n", \
        binary_to_uint("11111"));
    return;
}


/**** Problem 3 ****/

void evidence_analyze_weather(void) {
    printf("*** testing analyze_weather\n");
    struct observations obs_1 = {1.0, 1.5, 2.0};
    struct observations obs_2 = {1.5, 2.0, 2.5};
    struct observations obs_3 = {2.0, 2.5, 3.0};
    struct observations obs_4 = {2.5, 3.0, 3.5};
    struct observations obs_5 = {3.0, 3.5, 4.0};
    struct observations observations[] = {obs_1, obs_2, obs_3, obs_4, obs_5};
    unsigned int nobservations = 5;
    struct preferences prefs = {{1.5, 2.5}, {2.1, 2.9}, {1.5, 3.0}};
    struct preferences* preferences = &prefs;
    struct climate* climate = malloc(sizeof(struct climate));
    struct compatibility* compatibility = malloc(sizeof(struct compatibility));
    analyze_weather(observations, nobservations, climate, \
                    preferences, compatibility);
    printf("*climate:\n");
    printf("temps stats - avg:%lf min:%lf max:%lf\n", \
           climate->temps.avg, climate->temps.min, climate->temps.max);
    printf("humids stats - avg:%lf min:%lf max:%lf\n", \
           climate->humids.avg, climate->humids.min, climate->humids.max);
    printf("winds stats - avg:%lf min:%lf max:%lf\n", \
           climate->winds.avg, climate->winds.min, climate->winds.max);
    printf("*compatibility:\n");
    printf("good days: %u, bad days: %u, happiness: %lf\n", \
           compatibility->good_days, compatibility->bad_days, \
           compatibility->happiness);
    printf("testing whether the good_data and bad_data collected:\n");
    printf("temp of first good data: %lf\n", \
           compatibility->good_data[0]->temp);
    printf("humid of first bad data: %lf\n", \
           compatibility->bad_data[0]->humid);
    printf("wind of fourth (last) bad data: %lf\n", \
           compatibility->bad_data[3]->wind);
    free(climate);
    free(compatibility);
    free(compatibility->good_data);
    free(compatibility->bad_data);
    return;
}


/**** Problem 4 ****/

void evidence_element_weight(void) {
    printf("*** testing element_weight\n");
    struct element helium = {"helium", 4};
    struct element carbon = {"carbon", 12};
    struct element oxygen = {"oxygen", 16};
    printf("He: %u\n", element_weight(&helium));
    printf("C: %u\n", element_weight(&carbon));
    printf("O: %u\n", element_weight(&oxygen));
    return;
}

void evidence_molecule_weight(void) {
    printf("*** testing molecule_weight\n");
    struct element carbon = {"carbon", 12};
    struct element oxygen = {"oxygen", 16};
    struct element* elements[] = {&carbon, &oxygen};
    unsigned int atoms[] = {1, 2};
    struct molecule carbon_dioxide = {"carbon dioxide", 2, elements, atoms};
    printf("CO2: %u\n", molecule_weight(&carbon_dioxide));
    return;
}

void evidence_mixture_weight(void) {
    printf("*** testing mixture_weight\n");
    struct element helium = {"helium", 4};
    struct element carbon = {"carbon", 12};
    struct element oxygen = {"oxygen", 16};
    struct element* elements[] = {&carbon, &oxygen};
    unsigned int atoms[] = {1, 2};
    struct molecule carbon_dioxide = {"carbon dioxide", 2, elements, atoms};
    union chemical chem_1, chem_2;
    chem_1.element = &helium;
    chem_2.molecule = &carbon_dioxide;
    struct tagged_chemical He = {ELEMENT, chem_1};
    struct tagged_chemical CO_2 = {MOLECULE, chem_2};
    struct tagged_chemical chemicals[] = {He, CO_2};
    double moles[] = {1, 1};
    struct mixture mystery_mix = {"mystery", 2, chemicals, moles};
    printf("mystery_mix - 1 mol He + 1 mol CO2 - expecting 48: %u\n", \
           mixture_weight(&mystery_mix));
    return;
}

/*****************************************************************************/

int main() {
    evidence_concat();
    printf("\n");
    evidence_uint_to_binary();
    printf("\n");
    evidence_binary_to_uint();
    printf("\n");
    evidence_analyze_weather();
    printf("\n");
    evidence_element_weight();
    printf("\n");
    evidence_molecule_weight();
    printf("\n");
    evidence_mixture_weight();
    return 0;
}