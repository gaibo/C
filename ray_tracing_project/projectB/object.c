/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


char* object_tos(object o) {
    char* object_str = malloc(1024 * sizeof(char));
    char *tag, *sphere_poster_cylinder;
    switch (o.tag) {
        case SPHERE:
            tag = strdup("SPHERE");
            sphere_poster_cylinder = sphere_tos(o.o.s);
            break;
        case POSTER:
            tag = strdup("POSTER");
            sphere_poster_cylinder = poster_tos(o.o.p);
            break;
        case CYLINDER:
            tag = strdup("CYLINDER");
            sphere_poster_cylinder = cylinder_tos(o.o.c);
            break;
        default:
            fprintf(stderr, "error in object_tos: tag not recognized\n");
            exit(1);
    }
    sprintf(object_str, "(object %s, %s)", tag, sphere_poster_cylinder);
    char* object_str_out = strdup(object_str);
    free(object_str);
    free(sphere_poster_cylinder);
    free(tag);
    return object_str_out;
}

void object_show(FILE* f, object o) {
    char* object_str = object_tos(o);
    fprintf(f, "%s\n", object_str);
    free(object_str);
    return;
}