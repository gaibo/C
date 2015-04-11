/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

#include "raytracer.h"


v3 logical_loc(camera c, unsigned int x, unsigned int y) {
    //check for bounds
    if (x >= c.w || y >= c.h) {
        fprintf(stderr, "error in logical_loc: out of bounds\n");
        exit(1);
    }
    
    // start off with some declarations and defaults
    double left_start = -1.0;
    double top_start = 1.0;
    double pixel_base;
    
    // get details
    if (c.w == c.h) {
        pixel_base = c.w;   // arbitrary choice; also equal to c.h
    } else if (c.w > c.h) {
        pixel_base = c.w;
        top_start *= (double)c.h/c.w;
    } else if (c.h > c.w) {
        pixel_base = c.h;
        left_start *= (double)c.w/c.h;
    } else {
        fprintf(stderr, "error in logical_loc: impossible else\n");
        exit(1);
    }

    return v3_expr(left_start + (double)(1 + 2*x)/pixel_base,
                   top_start - (double)(1 + 2*y)/pixel_base,
                   0.0);
}

int shadow(v3 p, light l, obj_list* objs) {
    v3 nudge = v3_scale(0.0001, l.direction);
    v3 lifted = v3_add(p, nudge);
    ray shadow_ray;
    shadow_ray.origin = lifted;
    shadow_ray.direction = l.direction;
    hit_test ht_temp;
    while (objs != NULL) {
        ht_temp = intersect(shadow_ray, objs->obj);
        if (!ht_temp.miss) {
            return 1;
        }
        objs = objs->next;
    }
    return 0;
}

double my_max(double a, double b) {
    return (a > b) ? a : b;
}

rgb lighting(scene s, ray r, hit_test h) {
    switch (h.miss) {
        case MISS:
            return s.bg;
        case HIT:
            if (shadow(h.hit_point, s.light, s.objects)) {
                return rgb_modulate(h.surf, s.amb);
            } else {
                rgb diffuse = \
                    rgb_scale(my_max(0, v3_dot(h.surf_norm, \
                                               s.light.direction)), \
                              s.light.color);
                return rgb_modulate(h.surf, rgb_add(s.amb, diffuse));
            }
        default:
            fprintf(stderr, "error in lighting: unrecognized tag\n");
            exit(1);
    }
}

rgb trace_ray(scene s, ray r) {
    obj_list* objects = s.objects;
    double min_t = DBL_MAX;
    hit_test closest_hit;
    closest_hit.miss = 1;
    
    hit_test ht_temp;
    while (objects != NULL) {
        ht_temp = intersect(r, objects->obj);
        if (!ht_temp.miss && ht_temp.t < min_t) {
            min_t = ht_temp.t;
            closest_hit = ht_temp;
        }
        objects = objects->next;
    }
    
    return lighting(s, r, closest_hit);
}

void render(FILE* f, stage g) {
    fprintf(f, "P3\n");
    fprintf(f, "%u %u\n", g.c.w, g.c.h);
    fprintf(f, "255\n");
    int i_w, i_h;
    ray ray_from_cam;
    ray_from_cam.origin = g.c.loc;
    rgb color;
    for (i_h = 0; i_h < g.c.h; i_h++) {
        for (i_w = 0; i_w < g.c.w; i_w++) {
            ray_from_cam.direction = \
                v3_norm(v3_sub(logical_loc(g.c, i_w, i_h), g.c.loc));
            color = trace_ray(g.s, ray_from_cam);
            rgb_show_bytes(f, color);
        }
    }
    return;
}