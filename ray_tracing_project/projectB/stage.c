/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


char* stage_tos(stage stg) {
    char* stage_str = malloc(1024 * sizeof(char));
    char* c = camera_tos(stg.c);
    char* s = scene_tos(stg.s);
    sprintf(stage_str, "(stage\n\n%s\n\n%s", c, s);
    char* stage_str_out = strdup(stage_str);
    free(stage_str);
    free(s);
    free(c);
    return stage_str_out;
}

void stage_show(FILE* f, stage stg) {
    char* stage_str = stage_tos(stg);
    fprintf(f, "%s\n", stage_str);
    ol_show(f, stg.s.objects);
    fprintf(f, ")\n\n");
    fprintf(f, ")\n");
    free(stage_str);
    return;
}

stage get_stage(unsigned int selection) {
    switch (selection) {
        case 1:
            // Write-up sphere
            return stage_1();
        case 2:
            // Write-up/Prof. Shaw's official test poster
            return stage_2();
        case 3:
            // Prof. Shaw's official test sphere
            return stage_3();
        case 4:
            // Prof. Shaw's two-sphere setup
            return stage_4();
        case 5:
            // Prof. Shaw's funky juggling ball
            return stage_5();
        case 6:
            // For my own enjoyment - a large version of stage_4 to show off
            return stage_6();
        case 7:
            // My own juggling balls
            return stage_7();
        case 8:
            // Aesthetic adjustments to stage_7; wallpaper version
            return stage_8();
        case 9:
            // Write-up cylinders test template
            return stage_9();
        case 10:
            // Write-up shiny sphere
            return stage_10();
        default:
            return stage_1();
    }
}