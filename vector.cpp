// #define NDEBUG
#include <cassert>
#include "vector.hpp"


// 3-vector constructor
vector3::vector3(const vector3u& u)
: x(u.x), y(u.y), z(u.z) {};


// 3-vector subscript operator
double& vector3::operator[](int i)
{
    if      (i==0) {return x;}
    else if (i==1) {return y;}
    else if (i==2) {return z;}
    else {throw std::out_of_range("vector3 only has 3 components");}
}

const double& vector3::operator[](int i) const
{
    if      (i==0) {return x;}
    else if (i==1) {return y;}
    else if (i==2) {return z;}
    else {throw std::out_of_range("vector3 only has 3 components");}
}


// Unit vector constructors
vector3u::vector3u(double x, double y, double z)
: x(normed(vector3(x,y,z),0)),
  y(normed(vector3(x,y,z),1)),
  z(normed(vector3(x,y,z),2)) {};

vector3u::vector3u(const vector3& v)
: x(normed(v,0)),
  y(normed(v,1)),
  z(normed(v,2)) {};


// Unit vector normalization function
double vector3u::normed(const vector3& v, int component)
{
    assert(component<3);
    return v[component] / mag(v);
}


// Vector print functions
std::ostream& operator<<(std::ostream& os, const vector3& v)
{
    return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}


// Vector length functions
double mag(const vector3& v)
{
    assert(dot(v,v)>=0);// || isnan(dot(v,v)));
    return sqrt(dot(v,v));
}


// Vector product functions
double dot(const vector3& u, const vector3& v)
{
    return u.x*v.x + u.y*v.y + u.z*v.z;
}