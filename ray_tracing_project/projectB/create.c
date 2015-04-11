/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

#include "raytracer.h"


/* ================================== */
/* === Surface Coloring Functions === */
/* ================================== */

rgb k_purple(v3 cen, v3 loc) {
    return rgb_expr(0.5, 0.5, 0.8);
}

rgb k_white(v3 cen, v3 loc) {
    return rgb_expr(1, 1, 1);
}

rgb k_red(v3 cen, v3 loc) {
    return rgb_expr(1, 0, 0);
}

rgb k_silver(v3 cen, v3 loc) {
    return rgb_expr(0.75, 0.75, 0.75);
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


/* ================================== */
/* ============= Stages ============= */
/* ================================== */

// Write-up sphere
stage stage_1(void) {
    camera test_camera = {v3_expr(0, 0, -5), 240, 240};
    sphere test_sphere = {v3_expr(0, 0, 3), 1, &k_purple, rgb_expr(0, 0, 0)};
    object test_object;
    test_object.tag = SPHERE;
    test_object.o.s = test_sphere;
    obj_list* test_objects = ol_singleton(test_object);
    scene test_scene = {rgb_expr(0.3, 0.6, 1.0), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Write-up/Prof. Shaw's official test poster
stage stage_2(void) {
    camera test_camera = {v3_expr(0, 0, -5), 240, 240};
    poster test_poster = {v3_expr(-1, 1, 4), 2, 1, &k_purple, rgb_expr(0, 0, 0)};
    object test_object;
    test_object.tag = POSTER;
    test_object.o.p = test_poster;
    obj_list* test_objects = ol_singleton(test_object);
    scene test_scene = {rgb_expr(0.3, 0.6, 1.0), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Prof. Shaw's official test sphere
stage stage_3(void) {
    camera test_camera = {v3_expr(0, 0, -5), 120, 120};
    sphere test_sphere = {v3_expr(0, 0, 3), 1, &k_white, rgb_expr(0, 0, 0)};
    object test_object;
    test_object.tag = SPHERE;
    test_object.o.s = test_sphere;
    obj_list* test_objects = ol_singleton(test_object);
    scene test_scene = {rgb_expr(0.2, 0.2, 0.5), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(0.7, 0.7, 0.7)}, \
                        rgb_expr(0.1, 0.1, 0.1)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Prof. Shaw's two-sphere setup
stage stage_4(void) {
    camera test_camera = {v3_expr(0, 0, -5), 240, 240};
    sphere test_sphere_1 = {v3_expr(-0.5, 0.7, 3), 0.5, &k_white, rgb_expr(0, 0, 0)};
    sphere test_sphere_2 = {v3_expr(1, 0, 4), 1, &k_red, rgb_expr(0, 0, 0)};
    object test_object_1;
    test_object_1.tag = SPHERE;
    test_object_1.o.s = test_sphere_1;
    object test_object_2;
    test_object_2.tag = SPHERE;
    test_object_2.o.s = test_sphere_2;
    obj_list* test_objects = ol_cons(test_object_2, ol_singleton(test_object_1));
    scene test_scene = {rgb_expr(0.3, 0.6, 1.0), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Prof. Shaw's funky juggling ball
stage stage_5(void) {
    camera test_camera = {v3_expr(0, 0, -5), 240, 240};
    sphere test_sphere = {v3_expr(0, 0, 3), 1, &juggling_ball, rgb_expr(0, 0, 0)};
    object test_object;
    test_object.tag = SPHERE;
    test_object.o.s = test_sphere;
    obj_list* test_objects = ol_singleton(test_object);
    scene test_scene = {rgb_expr(0.3, 0.6, 1.0), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// For my own enjoyment - a large version of stage_4 to show off
stage stage_6(void) {
    camera test_camera = {v3_expr(0, 0, -5), 1080, 1920};
    sphere test_sphere_1 = {v3_expr(-0.5, 0.7, 3), 0.5, &k_white, rgb_expr(0, 0, 0)};
    sphere test_sphere_2 = {v3_expr(1, 0, 4), 1, &k_red, rgb_expr(0, 0, 0)};
    object test_object_1;
    test_object_1.tag = SPHERE;
    test_object_1.o.s = test_sphere_1;
    object test_object_2;
    test_object_2.tag = SPHERE;
    test_object_2.o.s = test_sphere_2;
    obj_list* test_objects = ol_cons(test_object_2, ol_singleton(test_object_1));
    scene test_scene = {rgb_expr(0.3, 0.6, 1.0), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// My own juggling balls
stage stage_7(void) {
    camera test_camera = {v3_expr(0, 0, -5), 2160, 3840};
    sphere test_sphere_1 = {v3_expr(-0.2, 0.5, 0.2), 0.5, &my_blue_juggling_ball, rgb_expr(0, 0, 0)};
    sphere test_sphere_2 = {v3_expr(0.75, 0, 0.5), 0.5, &my_green_juggling_ball, rgb_expr(0, 0, 0)};
    sphere test_sphere_3 = {v3_expr(-1.1, -0.1, 2), 0.5, &my_red_juggling_ball, rgb_expr(0, 0, 0)};
    sphere test_sphere_4 = {v3_expr(-0.1, -0.55, 3), 0.5, &my_yellow_juggling_ball, rgb_expr(0, 0, 0)};
    object test_object_1;
    test_object_1.tag = SPHERE;
    test_object_1.o.s = test_sphere_1;
    object test_object_2;
    test_object_2.tag = SPHERE;
    test_object_2.o.s= test_sphere_2;
    object test_object_3;
    test_object_3.tag = SPHERE;
    test_object_3.o.s = test_sphere_3;
    object test_object_4;
    test_object_4.tag = SPHERE;
    test_object_4.o.s = test_sphere_4;
    obj_list* test_objects = ol_cons(test_object_4, ol_cons(test_object_3, ol_cons(test_object_2, ol_singleton(test_object_1))));
    scene test_scene = {rgb_expr(0.9, 0.9, 0.9), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Aesthetic adjustments to stage_7; wallpaper version
stage stage_8(void) {
    camera test_camera = {v3_expr(0, 0, -5), 4320, 7680};
    sphere test_sphere_1 = {v3_expr(0.2, 0.5, 0.2), 0.5, &my_red_juggling_ball, rgb_expr(0.2, 0.2, 0.2)};
    sphere test_sphere_2 = {v3_expr(-0.75, 0, 0.5), 0.5, &my_green_juggling_ball, rgb_expr(0.2, 0.2, 0.2)};
    sphere test_sphere_3 = {v3_expr(1.1, -0.1, 2), 0.5, &my_yellow_juggling_ball, rgb_expr(0.2, 0.2, 0.2)};
    sphere test_sphere_4 = {v3_expr(0.1, -0.55, 3), 0.5, &my_blue_juggling_ball, rgb_expr(0.2, 0.2, 0.2)};
    object test_object_1;
    test_object_1.tag = SPHERE;
    test_object_1.o.s = test_sphere_1;
    object test_object_2;
    test_object_2.tag = SPHERE;
    test_object_2.o.s= test_sphere_2;
    object test_object_3;
    test_object_3.tag = SPHERE;
    test_object_3.o.s = test_sphere_3;
    object test_object_4;
    test_object_4.tag = SPHERE;
    test_object_4.o.s = test_sphere_4;
    obj_list* test_objects = ol_cons(test_object_4, ol_cons(test_object_3, ol_cons(test_object_2, ol_singleton(test_object_1))));
    scene test_scene = {rgb_expr(0.9, 0.9, 0.9), \
                        test_objects, \
                        {v3_norm(v3_expr(1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.2, 0.2, 0.2)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Write-up cylinders test template
stage stage_9(void) {
    camera test_camera = {v3_expr(0, 0, -5), 120, 120};
    cylinder test_cylinder = {v3_expr(0, -2, 0), 0.2, 4, &k_silver, rgb_expr(1, 1, 1)};
    object test_object;
    test_object.tag = CYLINDER;
    test_object.o.c = test_cylinder;
    obj_list* test_objects = ol_singleton(test_object);
    scene test_scene = {rgb_expr(0.4, 0.2, 0.1), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.3, 0.3, 0.3)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}

// Write-up shiny sphere
stage stage_10(void) {
    camera test_camera = {v3_expr(0, 0, -5), 300, 400};
    sphere test_sphere = {v3_expr(0, 0, 3), 1, &k_silver, rgb_expr(0.4, 0.4, 0.4)};
    object test_object;
    test_object.tag = SPHERE;
    test_object.o.s = test_sphere;
    obj_list* test_objects = ol_singleton(test_object);
    scene test_scene = {rgb_expr(0, 0, 0), \
                        test_objects, \
                        {v3_norm(v3_expr(-1, 1, -1)), rgb_expr(1, 1, 1)}, \
                        rgb_expr(0.1, 0.1, 0.1)};
    stage test_stage = {test_camera, test_scene};
    return test_stage;
}