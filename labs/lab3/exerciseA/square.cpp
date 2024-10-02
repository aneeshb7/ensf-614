/*  
 *  File Name: square.cpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#include "square.h"
#include "shape.h"
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

// Constructors
Square::Square(double x, double y, double s, char* name):Shape(x, y, name) {
    side_a = s;
}

// Getters
double Square::get_sideA() const
{
    return side_a;
}
// Setters
void Square::set_sideA(double s)
{
    side_a = s;
}

// Method Functions
const void Square::display()
{
    cout << "\nSquare Name: " << get_name();
    Shape::origin.display();
    cout  << "Side a: " << get_sideA() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
double Square::area()
{
    return side_a * side_a;
}

double Square::perimeter()
{
    return 4 * side_a;
}

