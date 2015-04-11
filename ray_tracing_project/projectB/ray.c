/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


v3 ray_position(ray r, double t) {
    return v3_add(r.origin, v3_scale(t, r.direction));
}

char* ray_tos(ray r) {
    char* ray_str = malloc(1024 * sizeof(char));
    char* origin = v3_tos(r.origin);
    char* direction = v3_tos(r.direction);
    sprintf(ray_str, "(ray %s->%s)", origin, direction);
    char* ray_str_out = strdup(ray_str);
    free(ray_str);
    free(direction);
    free(origin);
    return ray_str_out;
}

void ray_show(FILE* f, ray r) {
    char* ray_str = ray_tos(r);
    fprintf(f, "%s\n", ray_str);
    free(ray_str);
    return;
}