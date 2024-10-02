/*  
 *  File Name: shape.cpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#include "shape.h"
#include "point.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Constructors
Shape::Shape(double o_x, double o_y, const char* name):origin(o_x, o_y) {
    shapeName = new char[strlen(name)+1];
    strcpy(shapeName, name);
}
Shape::Shape(const Shape &s):origin(s.origin.x, s.origin.y) {
    shapeName = new char[strlen(s.shapeName) + 1];
    strcpy(shapeName, s.shapeName);
}
Shape& Shape::operator=(Shape &s) {
    delete [] shapeName;
    shapeName = new char[strlen(s.shapeName) + 1];
    strcpy(shapeName, s.shapeName);
    origin.x = s.origin.x;
    origin.y = s.origin.y;
    
    return *this;
}
// Destructors
Shape::~Shape() {
    delete []shapeName;
}

// Getters
const Point& Shape::get_origin() const {
    return origin;
}
const char* Shape::get_name() const {
    return shapeName;
}
// Setter
void Shape::set_origin(Point& p) {
    origin = p;
}
void Shape::set_name(char* name) {
    shapeName = name;
}

// Method Functions
const void Shape::display() {
    cout << "\nShape Name: " << shapeName << endl;
    origin.display();
}
double Shape::distance(Shape& s) {
    double dist;
    
    double dx = s.origin.x - origin.x;
    dx *= dx;
    double dy = s.origin.y - origin.y;
    dy *= dy;
    dist = sqrt(dy + dx);
    
    return dist;
}
double Shape::distance(Shape& s1, Shape& s2) {
    double dist;
    
    double dx = s1.origin.x - s2.origin.x;
    dx *= dx;
    double dy =s1.origin.y - s2.origin.y;
    dy *= dy;
    dist = sqrt(dy + dx);
    
    return dist;
}
void Shape::move(double dx, double dy) {
    double origX = origin.x;
    double origY = origin.y;
    origin.set_x(origX + dx);
    origin.set_y(origY + dy);
}
