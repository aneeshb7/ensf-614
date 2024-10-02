/*  
 *  File Name: curveCut.cpp
 *  Assignment: Lab 3 Exercise A
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Oct 2, 2024
 */

#include "curveCut.h"
#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include <cstring> 
#include <iostream>
#include <cmath>

using namespace std;

// Constructors
CurveCut::CurveCut(double x, double y, double r, double s_a, double s_b, char* name):Circle(x, y, r, name), Rectangle(x, y, s_a, s_b, name) {
    radius = r;
    side_a = s_a;
    side_b = s_b;
    if (radius > min(side_a, side_b)) {
        cout << "Error: Radius is too large for the sides of the rectangle." << endl;
        exit(1);
    }
}

// Getters
double CurveCut::get_radius() const {
    return radius;
}

double CurveCut::get_sideA() const {
    return side_a;
}

double CurveCut::get_sideB() const {
    return side_b;
}

// Setters
void CurveCut::set_radius(double r) {
    if (r > min(side_a, side_b)) {
        cout << "Error: Radius is too large for the sides of the rectangle." << endl;
        exit(1);
    }
    radius = r;
}

void CurveCut::set_sideA(double s_a) {
    if (radius > min(side_a, side_b)) {
        cout << "Error: Radius is too large for the sides of the rectangle." << endl;
        exit(1);
    }
    side_a = s_a;
}

void CurveCut::set_sideB(double s_b) {
    if (radius > min(side_a, side_b)) {
        cout << "Error: Radius is too large for the sides of the rectangle." << endl;
        exit(1);
    }
    side_b = s_b;
}

// Method Functions
const void CurveCut::display()
{
    cout << "\nCurveCut Name: " << get_name();
    Shape::origin.display();
    cout << "\nX-coordinate: " << Shape::origin.x << endl;
    cout << "Y-coordinate: " << Shape::origin.y << endl;
    cout << "Width: " << get_sideA() << endl;
    cout << "Length: " << get_sideB() << endl;
    cout << "Radius of the cut: " << get_radius() << endl;
}

double CurveCut::area()
{
    double area = 0;
    double quarterCircleArea = M_PI * radius * radius / 4;
    double rectangleArea = side_a * side_b;
    area = rectangleArea - quarterCircleArea;
    return area;
}

double CurveCut::perimeter()
{
    double perimeter = 0;
    double arcLength = M_PI * radius / 2;
    double rectanglePerimeter = 2 * side_a + 2 * side_b - 2 * radius;
    perimeter = arcLength + rectanglePerimeter;
    return perimeter;
}