/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


poster poster_expr(v3 ulc, double w, double h, rgb (*sc)(v3,v3), rgb sh) {
    poster poster_out;
    poster_out.upper_left = ulc;
    poster_out.w = w;
    poster_out.h = h;
    poster_out.surface_color = sc;
    poster_out.shine = sh;
    return poster_out;
}

char* poster_tos(poster s) {
    char* poster_str = malloc(1024 * sizeof(char));
    char* upper_left = v3_tos(s.upper_left);
    char* shine = rgb_tos(s.shine);
    sprintf(poster_str, "(poster %s, %.2f, %.2f, <FN>, %s)", \
        upper_left, s.w, s.h, shine);
    char* poster_str_out = strdup(poster_str);
    free(poster_str);
    free(shine);
    free(upper_left);
    return poster_str_out;
}

void poster_show(FILE* f, poster s) {
    char* poster_str = poster_tos(s);
    fprintf(f, "%s\n", poster_str);
    free(poster_str);
    return;
}