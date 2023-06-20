#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// defines a structure to line
struct Line {
    // Nested struct for a point with coordinates
    struct Point {
        float x;
        float y;
    } point1, point2;
    struct Point *midpoint; // pointer to the midpoint
    float slope, distance; // variables for slope and distance
};

// calculates the slope of a line
void solveSlope(struct Line *line) {
    line->slope = (line->point2.y - line->point1.y) / (line->point2.x - line->point1.x);
}

// calculates the midpoint of a line
void solveMidpoint(struct Line *line) {
    struct Point *mid = malloc(sizeof(struct Point));
    mid->x = (line->point1.x + line->point2.x) / 2;
    mid->y = (line->point1.y + line->point2.y) / 2;
    line->midpoint = mid;
}

// calculates the distance between two points on a line
void solveDistance(struct Line *line) {
    line->distance = sqrt(pow(line->point2.x - line->point1.x, 2) + pow(line->point2.y - line->point1.y, 2));
}

// converts the line equation to slope-intercept form
void getSlopeInterceptForm(struct Line *line) {
    line->slope = (line->point2.y - line->point1.y) / (line->point2.x - line->point1.x);
    float b = line->point2.y - line->slope * line->point2.x;
    printf("y = %fx + (%f)\n", line->slope, b);
}

int main() {
    struct Line line;
    printf("Enter x and y for point1: ");
    scanf("%f %f", &line.point1.x, &line.point1.y);
    printf("Enter x and y for point2: ");
    scanf("%f %f", &line.point2.x, &line.point2.y);

    solveSlope(&line);
    solveMidpoint(&line);
    solveDistance(&line);
    printf("Slope: %f\n", line.slope);
    printf("Midpoint: %f %f\n", line.midpoint->x, line.midpoint->y);
    printf("Distance between 2 points: %f\n", line.distance);
    getSlopeInterceptForm(&line);

    free(line.midpoint);

    return 0;
}
