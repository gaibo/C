/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


char* camera_tos(camera cm) {
    char* camera_str = malloc(1024 * sizeof(char));
    char* loc = v3_tos(cm.loc);
    sprintf(camera_str, "(camera %s, %u, %u)", loc, cm.h, cm.w);
    char* camera_str_out = strdup(camera_str);
    free(camera_str);
    free(loc);
    return camera_str_out;
}

void camera_show(FILE* f, camera cm) {
    char* camera_str = camera_tos(cm);
    fprintf(f, "%s\n", camera_str);
    free(camera_str);
    return;
}