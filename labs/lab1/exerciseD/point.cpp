#include <iostream>
#include "point.h"

Point::Point(double a, double b)
: x(a), y(b) 
{
}

Point::Point(): x(0), y(0) 
{
}

double Point::get_x()
{
    return x;
}

double Point::get_y()
{
    return y;
}

void Point::set_x(double a) { 
    x = a;
};

void Point::set_y(double a) { 
    y = a;
};