/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project B */

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

int is_within_cylinder_height(v3 pos, cylinder cylinder) {
    double y_diff = pos.y - cylinder.center.y;
    if (y_diff < 0 || y_diff > cylinder.height) {
        return 0;
    }
    return 1;
}

int is_closer(v3 origin, v3 pos_1, v3 pos_2) {
    if (v3_mag(v3_sub(pos_1, origin)) < v3_mag(v3_sub(pos_2, origin))) {
        return 1;
    } else {
        return 0;
    }
}

hit_test intersect(ray r, object obj) {
    v3 ro = r.origin;
    v3 rd = r.direction;
    hit_test ht_out;
    
    switch (obj.tag) {
        case SPHERE: {
            v3 sc = obj.o.s.center;
            double sr = obj.o.s.radius;
            v3 A = v3_sub(ro, sc);
            double B = v3_dot(A, rd);
            double C = v3_dot(A, A) - sr*sr;
            double D = B*B - C;
            double t = -B - sqrt(D);
            if (D > 0 && t > 0) {
                v3 pos = ray_position(r, t);
                ht_out.miss = HIT;
                ht_out.t = t;
                ht_out.hit_point = pos;
                ht_out.surf = (*(obj.o.s.surface_color))(sc, pos);
                ht_out.shine = obj.o.s.shine;
                ht_out.surf_norm = v3_norm(v3_sub(pos, sc));
            } else {
                ht_out.miss = MISS;
            }
            break;
        }
        case POSTER: {
            v3 n = v3_expr(0, 0, -1);
            double d = obj.o.p.upper_left.z;
            double t = -(v3_dot(ro, n) + d) / v3_dot(rd, n);
            v3 pos = ray_position(r, t);
            if (t > 0 && is_on_poster(pos, obj.o.p)) {
                ht_out.miss = HIT;
                ht_out.t = t;
                ht_out.hit_point = pos;
                ht_out.surf = \
                    (*(obj.o.p.surface_color))(obj.o.p.upper_left, pos);
                ht_out.shine = obj.o.p.shine;
                ht_out.surf_norm = n;
            } else {
                ht_out.miss = MISS;
            }
            break;
        }
        case CYLINDER: {
            v3 rp = v3_expr(rd.x, 0, rd.z);
            double mp = v3_mag(rp);
            v3 np = v3_norm(rp);
            double vx = np.x;
            double vz = np.z;
            double sx = ro.x;
            double sz = ro.z;
            v3 cc = obj.o.c.center;
            double cr = obj.o.c.radius;
            double xbar = sx - cc.x;
            double zbar = sz - cc.z;
            double A = vx*vx + vz*vz;
            double B = 2 * (xbar*vx + zbar*vz);
            double C = xbar*xbar + zbar*zbar - cr*cr;
            double D = B*B - 4*A*C;
            if (D >= 0) {
                double t_front = (-B - sqrt(D)) / (2*A);
                double t_back = (-B + sqrt(D)) / (2*A);
                v3 p_front = ray_position(r, t_front/mp);
                v3 p_back = ray_position(r, t_back/mp);
                if (is_closer(ro, p_front, p_back) && \
                    t_front > 0 && \
                    is_within_cylinder_height(p_front, obj.o.c)) {
                    // intersection is p_front
                    ht_out.miss = HIT;
                    ht_out.t = t_front/mp;
                    ht_out.hit_point = p_front;
                    ht_out.surf = (*(obj.o.c.surface_color))(cc, p_front);
                    ht_out.shine = obj.o.c.shine;
                    v3 axis_at_py = v3_expr(cc.x, p_front.y, cc.z);
                    ht_out.surf_norm = v3_norm(v3_sub(p_front, axis_at_py));
                } else if (t_back > 0 && \
                           is_within_cylinder_height(p_back, obj.o.c)) {
                    // intersection is p_back
                    ht_out.miss = HIT;
                    ht_out.t = t_back/mp;
                    ht_out.hit_point = p_back;
                    ht_out.surf = (*(obj.o.c.surface_color))(cc, p_back);
                    ht_out.shine = obj.o.c.shine;
                    v3 axis_at_py = v3_expr(cc.x, p_back.y, cc.z);
                    ht_out.surf_norm = v3_norm(v3_sub(axis_at_py, p_back));
                } else {
                    ht_out.miss = MISS;
                }
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