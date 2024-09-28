/*  
 *  File Name: rectangle.hpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>
#include <cstring>
#include <iostream>
#include "point.hpp"
#include "square.hpp"

class Rectangle: public Square {
private:
    double side_b;
    
public:
    // Constructors
    Rectangle(double x, double y, double s_a, double s_b, char* name);
    
    // Getters
    double get_sideB() const;
    // Setters
    void set_sideB(double s);
    
    // Method Functions
    const void display();
    double area();
    double perimeter();
};

#endif /* rectangle_hpp */
