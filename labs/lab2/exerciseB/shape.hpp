/*  
 *  File Name: shape.hpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#ifndef shape_hpp
#define shape_hpp

#include <stdio.h>
#include <cstring>
#include "point.hpp"
#include <string>

class Shape {
private:
    friend class Rectangle;
    friend class Square;
    Point origin;
    char* shapeName;
    
public:
    // Constructors
    Shape(double o_x, double o_y, const char* name);
    Shape(const Shape &s);
    Shape& operator =(Shape &s);
    // Destructors
    ~Shape();
    
    // Getters
    const Point& get_origin() const;
    const char* get_name() const;
    // Setters
    void set_origin(Point& p);
    void set_name(char* name);
    
    // Method Functions
    const virtual void display();
    double distance(Shape& other);      // a function that returns the distance between two points.
    static double distance(Shape& the_shape, Shape& other);
    void move (double dx, double dy);   // changes the position of the shape.
};

#endif /* shape_hpp */
