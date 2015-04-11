/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Project A */

#include "raytracer.h"


rgb rgb_expr(double r, double g, double b) {
    if (r < 0.0 || r > 1.0) {
        fprintf(stderr, "error in rgb_expr: r out of bounds\n");
        exit(1);
    } else if (g < 0.0 || g > 1.0) {
        fprintf(stderr, "error in rgb_expr: g out of bounds\n");
        exit(1);
    } else if (b < 0.0 || b > 1.0) {
        fprintf(stderr, "error in rgb_expr: b out of bounds\n");
        exit(1);
    }
    
    rgb rgb_out;
    rgb_out.r = r;
    rgb_out.g = g;
    rgb_out.b = b;
    return rgb_out;
}

rgb rgb_modulate(rgb c1, rgb c2) {
    rgb rgb_out;
    rgb_out.r = c1.r * c2.r;
    rgb_out.g = c1.g * c2.g;
    rgb_out.b = c1.b * c2.b;
    return rgb_out;
}

rgb rgb_scale(double s, rgb c) {
    double r_scaled = s * c.r;
    double g_scaled = s * c.g;
    double b_scaled = s * c.b;
    
    // clamping values
    if (r_scaled > 1) {
        r_scaled = 1;
    }
    if (g_scaled > 1) {
        g_scaled = 1;
    }
    if (b_scaled > 1) {
        b_scaled = 1;
    }
    if (r_scaled < 0) {
        r_scaled = 0;
    }
    if (g_scaled < 0) {
        g_scaled = 0;
    }
    if (b_scaled < 0) {
        b_scaled = 0;
    }
    
    rgb rgb_out;
    rgb_out.r = r_scaled;
    rgb_out.g = g_scaled;
    rgb_out.b = b_scaled;
    return rgb_out;
}

rgb rgb_add(rgb c1, rgb c2) {
    double r_sum = c1.r + c2.r;
    double g_sum = c1.g + c2.g;
    double b_sum = c1.b + c2.b;
    
    // clamping values
    if (r_sum > 1) {
        r_sum = 1;
    }
    if (g_sum > 1) {
        g_sum = 1;
    }
    if (b_sum > 1) {
        b_sum = 1;
    }
    
    rgb rgb_out;
    rgb_out.r = r_sum;
    rgb_out.g = g_sum;
    rgb_out.b = b_sum;
    return rgb_out;
}

char* rgb_tos(rgb c) {
    char* rgb_str = malloc(1024 * sizeof(char));
    sprintf(rgb_str, "(rgb (%.2f,%.2f,%.2f))", c.r, c.g, c.b);
    char* rgb_str_out = strdup(rgb_str);
    free(rgb_str);
    return rgb_str_out;
}

void rgb_show_bytes(FILE* f, rgb c) {
    int r = 255 * c.r;
    int g = 255 * c.g;
    int b = 255 * c.b;
    fprintf(f, "%d %d %d\n", r, g, b);
    return;
}