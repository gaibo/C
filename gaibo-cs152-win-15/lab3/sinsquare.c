/* Gaibo Zhang, gaibo */
/* CS152, Winter 2015 */
/* Lab 3 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]) {
    // setting some defaults
    int side_length = 480;
    double red_scale = 1.0;
    double green_scale = 1.0;
    double blue_scale = 1.0;
    
    // processing any command line arguments
    int k;
    
    for (k = 1; k < argc; k++) {
        if (!strcmp(argv[k], "-s")) {
            side_length = atoi(argv[k+1]);
        } else if (!strcmp(argv[k], "-r")) {
            red_scale = atof(argv[k+1]);
        } else if (!strcmp(argv[k], "-g")) {
            green_scale = atof(argv[k+1]);
        } else if (!strcmp(argv[k], "-b")) {
            blue_scale = atof(argv[k+1]);
        }
    }
    
    // setting up ppm before adding pixels
    printf("P3\n%d %d\n255\n", side_length, side_length);
    
    // generating pixels
    int pixel_x, pixel_y;
    double dist_from_center_x_squared, dist_from_center_y_squared;
    double dist_from_center;
    int r, g, b;
    
    for (pixel_x = 0; pixel_x < side_length; pixel_x++) {
        // save expense by doing part of distance calculation in this loop
        dist_from_center_x_squared = ((side_length/2) - pixel_x)
                                     * ((side_length/2) - pixel_x);
        for (pixel_y = 0; pixel_y < side_length; pixel_y++) {
            dist_from_center_y_squared = ((side_length/2) - pixel_y)
                                         * ((side_length/2) - pixel_y);
            dist_from_center = sqrt(dist_from_center_x_squared
                                    + dist_from_center_y_squared);
            // setting pixel color balance
            r = (int) 255/2 * (sin(red_scale*dist_from_center) + 1);
            g = (int) 255/2 * (sin(green_scale*dist_from_center) + 1);
            b = (int) 255/2 * (sin(blue_scale*dist_from_center) + 1);
            printf("%d %d %d\n", r, g, b);
        }
    }
    
    return 0;
}