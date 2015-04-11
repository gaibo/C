/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

#include "raytracer.h"


char* scene_tos(scene sc) {
    char* scene_str = malloc(1024 * sizeof(char));
    char* bg = rgb_tos(sc.bg);
    char* light = light_tos(sc.light);
    char* amb = rgb_tos(sc.amb);
    sprintf(scene_str, "(scene\nbg:\t%s\nlight:\t%s\namb:\t%s", bg, light, amb);
    char* scene_str_out = strdup(scene_str);
    free(scene_str);
    free(amb);
    free(light);
    free(bg);
    return scene_str_out;
}

void scene_show(FILE* f, scene sc) {
    char* scene_str = scene_tos(sc);
    fprintf(f, "%s\n", scene_str);
    ol_show(f, sc.objects);
    fprintf(f, ")\n");
    free(scene_str);
    return;
}