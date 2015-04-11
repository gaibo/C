/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


sphere sphere_expr(v3 v, double r, rgb (*sc)(v3, v3), rgb sh) {
    sphere sphere_out;
    sphere_out.center = v;
    sphere_out.radius = r;
    sphere_out.surface_color = sc;
    sphere_out.shine = sh;
    return sphere_out;
}

char* sphere_tos(sphere s) {
    char* sphere_str = malloc(1024 * sizeof(char));
    char* center = v3_tos(s.center);
    char* shine = rgb_tos(s.shine);
    sprintf(sphere_str, "(sphere %s, %.2f, <FN>, %s)", center, s.radius, shine);
    char* sphere_str_out = strdup(sphere_str);
    free(sphere_str);
    free(shine);
    free(center);
    return sphere_str_out;
}

void sphere_show(FILE* f, sphere s) {
    char* sphere_str = sphere_tos(s);
    fprintf(f, "%s\n", sphere_str);
    free(sphere_str);
    return;
}