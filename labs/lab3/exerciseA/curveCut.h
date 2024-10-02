/*  
 *  File Name: curveCut.h
 *  Assignment: Lab 3 Exercise A
 *  Lab Section: B01
 *  Completed by: Aneesh Bulusu and Kundai Dziwa
 *  Submission Date: Oct 2, 2024
 */

#ifndef curveCut_h
#define curveCut_h

#include <stdio.h>
#include <cstring>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"

class CurveCut: public Circle, public Rectangle {
    private:
        double radius;
        double side_a;
        double side_b;
    public:
        // Constructors
        CurveCut(double x, double y, double r, double s_a, double s_b, char* name);

        // Getters
        double get_radius() const;
        double get_sideA() const;
        double get_sideB() const;

        // Setters
        void set_radius(double r);
        void set_sideA(double s_a);
        void set_sideB(double s_b);

        // Method Functions
        const void display();
        double area();
        double perimeter();
};

#endif