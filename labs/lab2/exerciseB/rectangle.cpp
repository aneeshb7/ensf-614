/*  
 *  File Name: rectangle.cpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#include "rectangle.hpp"
#include "square.hpp"
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

// Constructors
Rectangle::Rectangle(double x, double y,  double s_a, double s_b, char* name):Square(x, y, s_a, name) {
    side_b = s_b;
}

// Getters
double Rectangle::get_sideB() const {
    return side_b;
}
// Setters
void Rectangle::set_sideB(double s) {
    side_b = s;
}

// Method Functions
const void Rectangle::display() {
    cout << "\nRectangle Name: " << get_name();
    Shape::origin.display();
    cout  << "Side a: " << get_sideA() << endl;
    cout  << "Side b: " << get_sideB() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
double Rectangle::area() {
    return side_b * get_sideA();
}
double Rectangle::perimeter() {
    double widths = side_b * 2;
    double heights = get_sideA() * 2;
    return widths + heights;
}

