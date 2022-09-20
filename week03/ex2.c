#include <stdio.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} Point;

double distance (Point A, Point B);

double area (Point A, Point B, Point C);

int main()
{
    Point A = {.x = 2.5, .y = 6};
    Point B = {.x = 1, .y = 2.2};
    Point C = {.x = 10, .y = 6};

    double AB = distance(A,B);
    double ABC = area(A,B,C);

    printf("%f %f\n",AB,ABC);
    return 0;
}

double distance (Point A, Point B){
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

double area (Point A, Point B, Point C){
    double x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y, x3 = C.x, y3 = C.y;
    return 0.5*(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3);

}
