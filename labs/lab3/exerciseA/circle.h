/*  
 *  File Name: square.hp
 *  Assignment: Lab 3 Exercise A
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Oct 2, 2024
 */

#ifndef circle_h
#define circle_h

#include <stdio.h>
#include <cstring>
#include "shape.h"

class Circle: virtual public Shape {
private:
    double radius;

public:
    // Constructors
    Circle(double x, double y, double r, char* name);
    
    // Getters
    double get_radius() const;
    // Setters
    void set_radius(double r);
 
    // Method Functions
    const void display();
    double area();
    double perimeter();
};

#endif