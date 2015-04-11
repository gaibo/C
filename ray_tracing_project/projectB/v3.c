/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


v3 v3_expr(double x, double y, double z) {
    v3 v3_out;
    v3_out.x = x;
    v3_out.y = y;
    v3_out.z = z;
    return v3_out;
}

v3 v3_add(v3 v1, v3 v2) {
    v3 v3_out;
    v3_out.x = v1.x + v2.x;
    v3_out.y = v1.y + v2.y;
    v3_out.z = v1.z + v2.z;
    return v3_out;
}

v3 v3_sub(v3 v1, v3 v2) {
    v3 v3_out;
    v3_out.x = v1.x - v2.x;
    v3_out.y = v1.y - v2.y;
    v3_out.z = v1.z - v2.z;
    return v3_out;
}

v3 v3_neg(v3 v) {
    v3 v3_out;
    v3_out.x = 0 - v.x;
    v3_out.y = 0 - v.y;
    v3_out.z = 0 - v.z;
    return v3_out;
}

v3 v3_scale(double s, v3 v) {
    v3 v3_out;
    v3_out.x = s * v.x;
    v3_out.y = s * v.y;
    v3_out.z = s * v.z;
    return v3_out;
}

double v3_dot(v3 v1, v3 v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

double v3_mag(v3 v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

v3 v3_norm(v3 v) {
    double mag = v3_mag(v);
    if (mag == 0) {
        return v;
    } else {
        v3 v3_out;
        v3_out.x = v.x/mag;
        v3_out.y = v.y/mag;
        v3_out.z = v.z/mag;
        return v3_out;
    }
}

char* v3_tos(v3 v) {
    char* v3_str = malloc(1024 * sizeof(char));
    sprintf(v3_str, "(v3 <%.2f,%.2f,%.2f>)", v.x, v.y, v.z);
    char* v3_str_out = strdup(v3_str);
    free(v3_str);
    return v3_str_out;
}

void v3_show(FILE* f, v3 v) {
    char* v3_str = v3_tos(v);
    fprintf(f, "%s\n", v3_str);
    free(v3_str);
    return;
}