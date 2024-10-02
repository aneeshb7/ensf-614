/*  
 *  File Name: square.h
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#ifndef square_h
#define square_h

#include <stdio.h>
#include <cstring>
#include "shape.h"


class Square: public Shape {
private:
    double side_a;
    
public:
    // Constructors
    Square(double x, double y, double s_a, char* name);
    
    // Getters
    double get_sideA() const;
    // Setters
    void set_sideA(double s);
 
    // Method Functions
    const void display();
    double area();
    double perimeter();
};

#endif /* square_hpp */
