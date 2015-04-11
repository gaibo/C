/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


char* light_tos(light l) {
    char* light_str = malloc(1024 * sizeof(char));
    char* direction = v3_tos(l.direction);
    char* color = rgb_tos(l.color);
    sprintf(light_str, "(light %s, %s)", direction, color);
    char* light_str_out = strdup(light_str);
    free(light_str);
    free(color);
    free(direction);
    return light_str_out;
}

void light_show(FILE* f, light l) {
    char* light_str = light_tos(l);
    fprintf(f, "%s\n", light_str);
    free(light_str);
    return;
}