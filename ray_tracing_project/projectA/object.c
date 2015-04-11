/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

#include "raytracer.h"


char* object_tos(object o) {
    char* object_str = malloc(1024 * sizeof(char));
    char *tag, *sphere_or_poster;
    if (o.tag == SPHERE) {
        tag = strdup("SPHERE");
        sphere_or_poster = sphere_tos(o.o.s);
    } else if (o.tag == POSTER) {
        tag = strdup("POSTER");
        sphere_or_poster = poster_tos(o.o.p);
    } else {
        fprintf(stderr, "error in object_tos: tag not recognized\n");
        exit(1);
    }
    sprintf(object_str, "(object %s, %s)", tag, sphere_or_poster);
    char* object_str_out = strdup(object_str);
    free(object_str);
    free(sphere_or_poster);
    free(tag);
    return object_str_out;
}

void object_show(FILE* f, object o) {
    char* object_str = object_tos(o);
    fprintf(f, "%s\n", object_str);
    free(object_str);
    return;
}