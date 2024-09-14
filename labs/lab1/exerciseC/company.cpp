#include <string>
#include <vector>
using namespace std;

struct Company{
    string companyName;
    vector<Employee> employees; // vector of employees
    vector<Customer> customers; // vector of customers
    Date dateEstablished;
};

struct Employee{
    string name;
    Address address;
    Date dateOfBirth;
    EmployeeState employeeState;
};

struct Customer{
    string name;
    Address address;
    string phoneNumber;
};

struct Address{
    string street;
    string city;
    string postalCode;
    string country;
};

struct Date{
    int day;
    int month;
    int year;
};

enum EmployeeState {
    ACTIVE, 
    SUSPENDED, 
    RETIRED,
    FIRED
};