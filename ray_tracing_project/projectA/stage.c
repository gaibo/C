/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

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


/**** Creating Stages ****/

rgb k_purple(v3 cen, v3 loc) {
    return rgb_expr(0.5, 0.5, 0.8);
}

rgb k_white(v3 cen, v3 loc) {
    return rgb_expr(1, 1, 1);
}

rgb k_red(v3 cen, v3 loc) {
    return rgb_expr(1, 0, 0);
}

rgb juggling_ball(v3 cen, v3 loc) {
    v3 from_center = v3_sub(loc, cen);
    if ((from_center.x > 0 && from_center.y > 0) || \
        (from_center.x < 0 && from_center.y < 0)) {
        return rgb_expr(0.2, 0.2, 0.2);
    } else {
        return rgb_expr(0.8, 0.8, 0.8);
    }
}

rgb my_green_juggling_ball(v3 cen, v3 loc) {
    v3 from_center = v3_sub(loc, cen);
    if ((from_center.x > 0 && from_center.y > 0) || \
        (from_center.x < 0 && from_center.y < 0)) {
        return rgb_expr(0, 0.33, 0);
    } else {
        return rgb_expr(0.99, 0.99, 0.99);
    }
}

rgb my_blue_juggling_ball(v3 cen, v3 loc) {
    v3 from_center = v3_sub(loc, cen);
    if ((from_center.x > 0 && from_center.y > 0) || \
        (from_center.x < 0 && from_center.y < 0)) {
        return rgb_expr(0, 0, 0.4);
    } else {
        return rgb_expr(0.99, 0.99, 0.99);
    }
}

rgb my_red_juggling_ball(v3 cen, v3 loc) {
    v3 from_center = v3_sub(loc, cen);
    if ((from_center.x > 0 && from_center.y > 0) || \
        (from_center.x < 0 && from_center.y < 0)) {
        return rgb_expr(0.58, 0, 0);
    } else {
        return rgb_expr(0.99, 0.99, 0.99);
    }
}

rgb my_yellow_juggling_ball(v3 cen, v3 loc) {
    v3 from_center = v3_sub(loc, cen);
    if ((from_center.x > 0 && from_center.y > 0) || \
        (from_center.x < 0 && from_center.y < 0)) {
        return rgb_expr(0.80, 0.65, 0);
    } else {
        return rgb_expr(0.99, 0.99, 0.99);
    }
}

stage get_stage(unsigned int selection) {
    switch (selection) {
        case 2: {
            // write-up/Prof. Shaw's official poster
            camera test_camera = {{0, 0, -5}, 240, 240};
            poster test_poster = {{-1, 1, 4}, 2, 1, &k_purple, {0, 0, 0}};
            object test_object;
            test_object.tag = POSTER;
            test_object.o.p = test_poster;
            obj_list* test_objects = ol_singleton(test_object);
            scene test_scene = {{0.3, 0.6, 1.0}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        case 3: {
            // Prof. Shaw's official sphere
            camera test_camera = {{0, 0, -5}, 120, 120};
            sphere test_sphere = {{0, 0, 3}, 1, &k_white, {0, 0, 0}};
            object test_object;
            test_object.tag = SPHERE;
            test_object.o.s = test_sphere;
            obj_list* test_objects = ol_singleton(test_object);
            scene test_scene = {{0.2, 0.2, 0.5}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {0.7, 0.7, 0.7}}, {0.1, 0.1, 0.1}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        case 4: {
            // Prof. Shaw's two-sphere setup
            camera test_camera = {{0, 0, -5}, 240, 240};
            sphere test_sphere_1 = {{-0.5, 0.7, 3}, 0.5, &k_white, {0, 0, 0}};
            sphere test_sphere_2 = {{1, 0, 4}, 1, &k_red, {0, 0, 0}};
            object test_object_1;
            test_object_1.tag = SPHERE;
            test_object_1.o.s = test_sphere_1;
            object test_object_2;
            test_object_2.tag = SPHERE;
            test_object_2.o.s = test_sphere_2;
            obj_list* test_objects = \
                ol_cons(test_object_2, ol_singleton(test_object_1));
            scene test_scene = {{0.3, 0.6, 1.0}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        case 5: {
            // Prof. Shaw's funky juggling ball
            camera test_camera = {{0, 0, -5}, 240, 240};
            sphere test_sphere = {{0, 0, 3}, 1, &juggling_ball, {0, 0, 0}};
            object test_object;
            test_object.tag = SPHERE;
            test_object.o.s = test_sphere;
            obj_list* test_objects = ol_singleton(test_object);
            scene test_scene = {{0.3, 0.6, 1.0}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        case 6: {
            // For my own enjoyment - a large version of 4 to show off
            camera test_camera = {{0, 0, -5}, 1080, 1920};
            sphere test_sphere_1 = {{-0.5, 0.7, 3}, 0.5, &k_white, {0, 0, 0}};
            sphere test_sphere_2 = {{1, 0, 4}, 1, &k_red, {0, 0, 0}};
            object test_object_1;
            test_object_1.tag = SPHERE;
            test_object_1.o.s = test_sphere_1;
            object test_object_2;
            test_object_2.tag = SPHERE;
            test_object_2.o.s = test_sphere_2;
            obj_list* test_objects = \
                ol_cons(test_object_2, ol_singleton(test_object_1));
            scene test_scene = {{0.3, 0.6, 1.0}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        case 7: {
            // My own juggling balls
            camera test_camera = {{0, 0, -5}, 2160, 3840};
            sphere test_sphere_1 = {{-0.2, 0.5, 0.2}, 0.5, &my_blue_juggling_ball, {0, 0, 0}};
            sphere test_sphere_2 = {{0.75, 0, 0.5}, 0.5, &my_green_juggling_ball, {0, 0, 0}};
            sphere test_sphere_3 = {{-0.1, -0.55, 3}, 0.5, &my_yellow_juggling_ball, {0, 0, 0}};
            sphere test_sphere_4 = {{-1.1, -0.1, 2}, 0.5, &my_red_juggling_ball, {0, 0, 0}};
            object test_object_1;
            test_object_1.tag = SPHERE;
            test_object_1.o.s = test_sphere_1;
            object test_object_2;
            test_object_2.tag = SPHERE;
            test_object_2.o.s = test_sphere_2;
            object test_object_3;
            test_object_3.tag = SPHERE;
            test_object_3.o.s = test_sphere_3;
            object test_object_4;
            test_object_4.tag = SPHERE;
            test_object_4.o.s = test_sphere_4;
            obj_list* test_objects = \
                ol_cons(test_object_4, ol_cons(test_object_3, ol_cons(test_object_2, ol_singleton(test_object_1))));
            scene test_scene = {{0.9, 0.9, 0.9}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        case 8: {
            // Aesthetic adjustments to case 7
            camera test_camera = {{0, 0, -5}, 4320, 7680};
            sphere test_sphere_1 = {{0.2, 0.5, 0.2}, 0.5, &my_red_juggling_ball, {0, 0, 0}};
            sphere test_sphere_2 = {{-0.75, 0, 0.5}, 0.5, &my_green_juggling_ball, {0, 0, 0}};
            sphere test_sphere_3 = {{0.1, -0.55, 3}, 0.5, &my_blue_juggling_ball, {0, 0, 0}};
            sphere test_sphere_4 = {{1.1, -0.1, 2}, 0.5, &my_yellow_juggling_ball, {0, 0, 0}};
            object test_object_1;
            test_object_1.tag = SPHERE;
            test_object_1.o.s = test_sphere_1;
            object test_object_2;
            test_object_2.tag = SPHERE;
            test_object_2.o.s = test_sphere_2;
            object test_object_3;
            test_object_3.tag = SPHERE;
            test_object_3.o.s = test_sphere_3;
            object test_object_4;
            test_object_4.tag = SPHERE;
            test_object_4.o.s = test_sphere_4;
            obj_list* test_objects = \
                ol_cons(test_object_4, ol_cons(test_object_3, ol_cons(test_object_2, ol_singleton(test_object_1))));
            scene test_scene = {{0.9, 0.9, 0.9}, test_objects, \
                {v3_norm(v3_expr(1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
        default: {
            // write-up official sphere
            camera test_camera = {{0, 0, -5}, 240, 240};
            sphere test_sphere = {{0, 0, 3}, 1, &k_purple, {0, 0, 0}};
            object test_object;
            test_object.tag = SPHERE;
            test_object.o.s = test_sphere;
            obj_list* test_objects = ol_singleton(test_object);
            scene test_scene = {{0.3, 0.6, 1.0}, test_objects, \
                {v3_norm(v3_expr(-1, 1, -1)), {1, 1, 1}}, {0.2, 0.2, 0.2}};
            stage test_stage = {test_camera, test_scene};
            return test_stage;
        }
    }
}