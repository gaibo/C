/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


obj_list* ol_cons(object o, obj_list* os) {
    obj_list* new_head = malloc(sizeof(obj_list));
    new_head->obj = o;
    new_head->next = os;
    return new_head;
}

obj_list* ol_singleton(object s) {
    obj_list* new_head = malloc(sizeof(obj_list));
    new_head->obj = s;
    new_head->next = NULL;
    return new_head;
}

void ol_show(FILE* f, obj_list* os) {
    char* object_str;
    fprintf(f, "objs:\t");
    while (os != NULL) {
        object_str = object_tos(os->obj);
        fprintf(f, "%s | ", object_str);
        free(object_str);
        os = os->next;
    }
    fprintf(f, "\n");
    return;
}

void ol_free(obj_list* ss) {
    if (ss != NULL) {
        ol_free(ss->next);
        free(ss);
    }
    return;
}