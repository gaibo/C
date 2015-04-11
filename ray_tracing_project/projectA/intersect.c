/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

#include "raytracer.h"


int is_on_poster(v3 pos, poster poster) {
    if (pos.z != poster.upper_left.z) {
        fprintf(stderr, "error in is_on_poster: z don't match!\n");
        exit(1);
    }
    double x_diff = pos.x - poster.upper_left.x;
    if (x_diff < 0 || x_diff > poster.w) {
        return 0;
    }
    double y_diff = poster.upper_left.y - pos.y;
    if (y_diff < 0 || y_diff > poster.h) {
        return 0;
    }
    return 1;
}

hit_test intersect(ray r, object obj) {
    v3 ro = r.origin;
    v3 rd = r.direction;
    double t;
    hit_test ht_out;
    
    switch (obj.tag) {
        case SPHERE: {
            v3 sc = obj.o.s.center;
            double sr = obj.o.s.radius;
            v3 A = v3_sub(ro, sc);
            double B = v3_dot(A, rd);
            double C = v3_dot(A, A) - sr*sr;
            double D = B*B - C;
            t = -B - sqrt(D);
            if (D > 0 && t > 0) {
                v3 ray_pos = ray_position(r, t);
                ht_out.miss = HIT;
                ht_out.t = t;
                ht_out.hit_point = ray_pos;
                ht_out.surf = \
                    (*(obj.o.s.surface_color))(obj.o.s.center, ray_pos);
                ht_out.shine = obj.o.s.shine;
                ht_out.surf_norm = v3_norm(v3_sub(ray_pos, obj.o.s.center));
            } else {
                ht_out.miss = MISS;
            }
            break;
        }
        case POSTER: {
            v3 n = v3_expr(0, 0, -1);
            double d = obj.o.p.upper_left.z;
            t = -(v3_dot(ro, n) + d) / v3_dot(rd, n);
            v3 ray_pos = ray_position(r, t);
            if (t > 0 && is_on_poster(ray_pos, obj.o.p)) {
                ht_out.miss = HIT;
                ht_out.t = t;
                ht_out.hit_point = ray_pos;
                ht_out.surf = \
                    (*(obj.o.p.surface_color))(obj.o.p.upper_left, ray_pos);
                ht_out.shine = obj.o.p.shine;
                ht_out.surf_norm = n;
            } else {
                ht_out.miss = MISS;
            }
            break;
        }
        default:
            fprintf(stderr, "error in intersect: unrecognized tag\n");
            exit(1);
    }
    
    return ht_out;
}