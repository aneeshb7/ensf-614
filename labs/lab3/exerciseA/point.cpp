/*  
 *  File Name: point.cpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#include "point.h"
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constructors
int Point::id = 1000;
Point::Point(double a, double b){
    this->x = a;
    this->y = b;
    this->id++;
}

// Getters
double Point::get_x()const {
    return this->x;
}
double Point::get_y()const {
    return this->y;
}
int Point::get_id() const {
    return this->id;
}
// Setters
void Point::set_x(double a) {
    this->x = a;
}
void Point::set_y(double b) {
    this->y = b;
}
void Point::set_id(int p_id) {
    this->id = p_id;
}

// Method functions
void Point::display() const {
    cout << fixed;
    cout << setprecision(2) << "\nX-coordinate: " << x << endl;
    cout << setprecision(2) << "Y-coordinate: " << y << endl;
}
double Point::distance(Point& p) {
    double dist;
    
    double dx = p.x - x;
    dx *= dx;
    double dy = p.y - y;
    dy *= dy;
    dist = sqrt(dy + dx);
    
    return dist;
}
double Point::distance(Point& p, Point& q) {
    double dist;
    
    double dx = p.x - q.x;
    dx *= dx;
    double dy = p.y - q.y;
    dy *= dy;
    dist = sqrt(dy + dx);
    
    return dist;
}
int Point::counter() {
    return id - 1000;
}
