#include <stdio.h>
#include <math.h>

typedef struct Point
{
    double x, y;
}Point;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main()
{
    Point p1, p2;

    double x1 = 2, y1 = -3, x2 = -4, y2 = 5;

    p1.x = 2.0;
    p1.y = -3.0;

    p2.x = -4.0;
    p2.y = 5.0;

    p1 = createPoint(2, -3);
    p2 = createPoint(-4, 5);

    printPoint(p1);
    printPoint(p2);

    printf("%.2f\n", getDistance(createPoint(2, -3), createPoint(-4, 5)));

    return 0;
}

void printPoint(Point p)
{
    printf("(%.2f; %.2f)\n", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double getDistance(Point a, Point b)
{
    double l = sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
    return l;
}