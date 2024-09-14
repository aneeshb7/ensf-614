#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
using namespace std;

// class Human: GENERAL CONCEPTS
//   A Human object is a person with a name and a location on a Cartesian Plane.
//   The name of a Human object is a string.
//   The location of a Human object is a Point object.
//   The name of a Human object can be set and retrieved.
//   The location of a Human object can be retrieved and set when the Human is created.

#include "point.h"

typedef char* name;
typedef Point location;

class Human{
    protected:
        Point location;   // Location of an object of Human on a Cartesian Plane
        char *name;       // Human's name

    public:
        Human(const char* name, double x, double y);
        Human(const Human& source);
        Human& operator=(const Human& source);
        ~Human();

        char* get_name();
        // PROMISES: Returns the name of the Human object.

        void set_name(char* name);
        // PROMISES: Sets the name of the Human object to name.

        Point get_point()const;
        // PROMISES: Returns the location of the Human object.

        void display();
        // PROMISES: Displays the name and location of the Human object.
};

#endif