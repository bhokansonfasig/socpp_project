/* Module for vectors designed to work for particle module
 * Includes:
 *   vector3 struct (3D vector with x, y, z)
 *   vector3u struct (3D unit vector: normalized to length 1)
 *   vector4 struct (4D vector with w, x, y, z)
 *   Functions for manipulating vectors
 *
 * Written by Ben Hokanson-Fasig for IceCube's Summer of C++ 2017
 */


//Include guard
#ifndef __VECTORS_HPP_INCLUDED__
#define __VECTORS_HPP_INCLUDED__

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>


// Forward-declare vector3u for vector3 constructor
struct vector3u;


struct vector3
{
    // Attributes
    double x, y, z;
    
    // Constructor
    vector3(double x=0, double y=0, double z=0)
    : x(x), y(y), z(z) {};
    vector3(const vector3u& u);
    // Destructor
    ~vector3() = default;
    // Copy Constructor
    vector3(const vector3&) = default;
    // Move Constructor
    vector3(vector3&&) = default;
    // Copy Assignment
    vector3& operator=(const vector3&) = default;
    // Move Assignment
    vector3& operator=(vector3&&) = default;

    // Subscript operator
    double& operator[](int i);
    const double& operator[](int i) const;

    // Arithmetic operations
    vector3& operator+=(const vector3& rhs);
    vector3& operator-=(const vector3& rhs);
    vector3& operator*=(const double rhs);
};

struct vector3u
{
    // Attributes
    const double x, y, z;
    
    // Constructor
    vector3u(double x=0, double y=0, double z=1);
    explicit vector3u(const vector3& v);
    // Destructor
    ~vector3u() = default;
    // Copy Constructor
    vector3u(const vector3u&) = default;
    // Move Constructor
    vector3u(vector3u&&) = default;
    // Copy Assignment
    vector3u& operator=(const vector3u&) = default;
    // Move Assignment
    vector3u& operator=(vector3u&&) = default;

    private:
        static double normed(const vector3& v, int component);
};

struct vector4
{
    // Attributes
    double w, x, y, z;

    // Constructor
    vector4(double w=0, double x=0, double y=0, double z=0)
    : w(w), x(x), y(y), z(z) {};
    // Destructor
    ~vector4() = default;
    // Copy Constructor
    vector4(const vector4&) = default;
    // Move Constructor
    vector4(vector4&&) = default;
    // Copy Assignment
    vector4& operator=(const vector4&) = default;
    // Move Assignment
    vector4& operator=(vector4&&) = default;

    // Subscript operator
    double& operator[](int i);
    const double& operator[](int i) const;

    // Arithmetic operations
    vector4& operator+=(const vector4& rhs);
    vector4& operator-=(const vector4& rhs);
    vector4& operator*=(const double rhs);
};



// Vector print functions
std::ostream& operator<<(std::ostream& os, const vector3& v);

std::ostream& operator<<(std::ostream& os, const vector4& v);


// Vector magnitude functions
double mag(const vector3& v);

double mag(const vector4& v);


// Vector arithmetic functions
vector3 operator+(const vector3& lhs, const vector3& rhs);
vector3 operator-(const vector3& lhs, const vector3& rhs);
vector3 operator*(const vector3& lhs, const double rhs);
vector3 operator*(const double lhs, const vector3& rhs);

vector4 operator+(const vector4& lhs, const vector4& rhs);
vector4 operator-(const vector4& lhs, const vector4& rhs);
vector4 operator*(const vector4& lhs, const double rhs);
vector4 operator*(const double lhs, const vector4& rhs);


// Vector product functions
double dot(const vector3& u, const vector3& v);
vector3 cross(const vector3& u, const vector3& v);

double dot(const vector4& u, const vector4& v);


#endif
