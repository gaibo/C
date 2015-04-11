/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


cylinder cylinder_expr(v3 v, double r, double h, rgb (*sc)(v3,v3), rgb sh) {
    cylinder cylinder_out;
    cylinder_out.center = v;
    cylinder_out.radius = r;
    cylinder_out.height = h;
    cylinder_out.surface_color = sc;
    cylinder_out.shine = sh;
    return cylinder_out;
}

char* cylinder_tos(cylinder s) {
    char* cylinder_str = malloc(1024 * sizeof(char));
    char* center = v3_tos(s.center);
    char* shine = rgb_tos(s.shine);
    sprintf(cylinder_str, "(cylinder %s, %.2f, %.2f, <FN>, %s)", \
        center, s.radius, s.height, shine);
    char* cylinder_str_out = strdup(cylinder_str);
    free(cylinder_str);
    free(shine);
    free(center);
    return cylinder_str_out;
}

void cylinder_show(FILE* f, cylinder s) {
    char* cylinder_str = cylinder_tos(s);
    fprintf(f, "%s\n", cylinder_str);
    free(cylinder_str);
    return;
}