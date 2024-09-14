#ifndef POINT_H
#define POINT_H
#include <iostream>

// class Point: GENERAL CONCEPTS
//
//    A Point object is a point in a two-dimensional Cartesian plane.
//    The x and y coordinates of a Point object can be set and retrieved.
//    The x and y coordinates of a Point object are double-precision.

typedef int x;
typedef int y;

class Point{
private:
    double x;     // x coordinate of a location on Cartesian Plane
    double y;     // y coordinate of a location on Cartesian Plane

public:
    Point();
    Point(double a, double b);

    double get_x();
    // PROMISES: Returns the x coordinate of the point.

    double get_y();
    // PROMISES: Returns the y coordinate of the point.

    void set_x(double a);
    // PROMISES: Sets the x coordinate of the point to a.

    void set_y(double a);
    // PROMISES: Sets the y coordinate of the point to a.
};

#endif