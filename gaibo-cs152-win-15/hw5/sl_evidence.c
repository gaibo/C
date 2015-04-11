/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Homework 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_list.h"


void evidence_sl_sorted_asc(void) {
    printf("***testing sl_sorted_asc\n");
    string_list *test1 = malloc(sizeof(string_list));
    string_list *test2 = malloc(sizeof(string_list));
    string_list *test3 = malloc(sizeof(string_list));
    test1->val = "test1";
    test1->next = test2;
    test2->val = "test2";
    test2->next = test3;
    test3->val = "test3";
    test3->next = NULL;
    printf("this should be sorted. expecting 1: %d\n", sl_sorted_asc(test1));
    test1->val = "z";
    test1->next = test2;
    test2->val = "y";
    test2->next = test3;
    test3->val = "x";
    test3->val = NULL;
    printf("this should not be. expecting 0: %d\n", sl_sorted_asc(test1));
    free(test1);
    free(test2);
    free(test3);
    return;
}

void list_printer(string_list* list) {
    if (list == NULL) {
        printf("empty list!\n");
    }
    while (list != NULL) {
        printf("%s\n", list->val);
        list = list->next;
    }
    return;
}

void free_list(string_list* list) {
    if (list == NULL) {
        return;
    }
    if (list->next != NULL) {
        free_list(list->next);
    }
    free(list);
    return;
}

void evidence_sl_insert(void) {
    printf("***testing sl_insert\n");
    string_list* test1 = malloc(sizeof(string_list));
    string_list* test2 = malloc(sizeof(string_list));
    string_list* test3 = malloc(sizeof(string_list));
    test1->val = "test1";
    test1->next = test2;
    test2->val = "test2";
    test2->next = test3;
    test3->val = "test3";
    test3->next = NULL;
    list_printer(sl_insert("test4", test1));
    free_list(test1);
    string_list* testx = malloc(sizeof(string_list));
    string_list* testy = malloc(sizeof(string_list));
    string_list* testz = malloc(sizeof(string_list));
    testx->val = "x";
    testx->next = testy;
    testy->val = "y";
    testy->next = testz;
    testz->val = "z";
    testz->next = NULL;
    string_list* new_head = sl_insert("w", testx);
    list_printer(new_head);
    free_list(new_head);
    return;
}

int is_test1(char* s) {
    if (strcmp(s, "test1") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void evidence_sl_filter(void) {
    printf("***testing sl_filter\n");
    string_list* test1 = malloc(sizeof(string_list));
    string_list* test2 = malloc(sizeof(string_list));
    string_list* test3 = malloc(sizeof(string_list));
    test1->val = malloc(6*sizeof(char));
    test2->val = malloc(6*sizeof(char));
    test3->val = malloc(6*sizeof(char));
    strcpy(test1->val, "test1");
    test1->next = test2;
    strcpy(test2->val, "test2");
    test2->next = test3;
    strcpy(test3->val, "test3");
    test3->next = NULL;
    printf("should print test1:\n");
    list_printer(sl_filter(&is_test1, test1));
    free_list(test1);
    string_list* testx = malloc(sizeof(string_list));
    string_list* testy = malloc(sizeof(string_list));
    string_list* testz = malloc(sizeof(string_list));
    testx->val = malloc(2*sizeof(char));
    testy->val = malloc(2*sizeof(char));
    testz->val = malloc(2*sizeof(char));
    strcpy(testx->val, "x");
    testx->next = testy;
    strcpy(testy->val, "y");
    testy->next = testz;
    strcpy(testz->val, "z");
    testz->next = NULL;
    string_list* temp = sl_filter(&is_test1, testx);
    printf("should print empty list:\n");
    list_printer(temp);
    free_list(temp);
    return;
}

int main() {
    evidence_sl_sorted_asc();
    evidence_sl_insert();
    evidence_sl_filter();
    return 0;
}