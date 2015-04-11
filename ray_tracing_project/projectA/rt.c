/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

#include "raytracer.h"


int main(int argc, char* argv[]) {
    unsigned int selection = (argc > 1) ? atoi(argv[1]) : 1;
    stage stg = get_stage(selection);
    render(stdout, stg);
    stage_show(stderr, stg);
    ol_free(stg.s.objects);
    return 0;
}