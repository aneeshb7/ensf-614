/*  
 *  File Name: point.hpp
 *  Assignment: Lab 2 Exercise B
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Sept 23, 2024
 */

#ifndef point_hpp
#define point_hpp

#include <stdio.h>
#include <cstring>

class Point
{
private:
    static int id;         // an automatically set id number for the point
    double x;       // x coordinate of a location on Cartisian Plain
    double y;       // y coordinate of a location on Cartisian Plain
    friend class Shape;
    
public:
    // Constructors
    Point(double a, double b);
    
    // Getters
    double get_x()const;
    double get_y()const;
    int get_id()const;
    // Setters
    void set_x(double a);
    void set_y(double a);
    void set_id(int p_id);
    
    // Member Functions
    void display() const;   // Displays x, and y coordinates of the point.
    double distance(Point& p);      // a function that returns the distance between two points.
    static double distance(Point& p, Point& q);
    int counter(); // returns the count of how many Point objects there are.
};

#endif /* point_hpp */
