#include <cstring>
#include <iostream>
#include "human.h"
#include "point.h"
using namespace std;

Human::Human(const char *name = "", double x = 0, double y = 0) : name(new char[strlen(name) + 1])
{
    strcpy(this->name, name);
    location.set_x(x);
    location.set_y(y);
}

Human::Human(const Human &source) : name(new char[strlen(source.name) + 1])
{
    strcpy(name, source.name);
    location = source.location;
}

Human& Human::operator=(const Human &source)
{
    if (this != &source)
    {
        delete[] name;
        name = new char[strlen(source.name) + 1];
        strcpy(name, source.name);
        location = source.location;
    }
    return *this;
}

char *Human::get_name() 
{ 
    return name;
}

void Human::set_name(char *name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Point Human::get_point() const 
{ 
    return location; 
}

void Human::display()
{
    cout << "Human Name: " << name << "\nHuman Location: "
         << location.get_x() << ", "
         << location.get_y() << ".\n"
         << endl;
}

Human::~Human()
{
    delete[] name;
}
