/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


char* hit_test_tos(hit_test t) {
    char* hit_test_str = malloc(1024 * sizeof(char));
    char* miss;
    if (t.miss == 1) {
        miss = strdup("MISS");
    } else if (t.miss == 0) {
        miss = strdup("HIT");
    } else {
        fprintf(stderr, "error in hit_test_tos: tag not recognized\n");
        exit(1);
    }
    char* hit_point = v3_tos(t.hit_point);
    char* surf = rgb_tos(t.surf);
    char* shine = rgb_tos(t.shine);
    char* surf_norm = v3_tos(t.surf_norm);
    sprintf(hit_test_str, "(hit_test %s, %.2f, %s, %s, %s, %s)", \
        miss, t.t, hit_point, surf, shine, surf_norm);
    char* hit_test_str_out = strdup(hit_test_str);
    free(hit_test_str);
    free(surf_norm);
    free(shine);
    free(surf);
    free(hit_point);
    return hit_test_str_out;
}

void hit_test_show(FILE* f, hit_test t) {
    char* hit_test_str = hit_test_tos(t);
    fprintf(f, "%s\n", hit_test_str);
    free(hit_test_str);
    return;
}