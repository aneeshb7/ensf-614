/*  
 *  File Name: circle.cpp
 *  Assignment: Lab 3 Exercise A
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Oct 2, 2024
 */

#include "circle.h"
#include "shape.h"
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

// Constructors
Circle::Circle(double x, double y, double r, char* name): Shape(x, y, name) {
    radius = r;
}

// Getters
double Circle::get_radius() const
{
    return radius;
}

// Setters
void Circle::set_radius(double r)
{
    radius = r;
}

// Method Functions
const void Circle::display()
{
    cout << "\nCircle Name: " << get_name();
    Shape::origin.display();
    cout  << "Radius: " << get_radius() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

double Circle::area()
{
    return M_PI * radius * radius;
}

double Circle::perimeter()
{
    return 2 * M_PI * radius;
}