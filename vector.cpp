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


// 3-vector arithmetic operations
vector3& vector3::operator+=(const vector3& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

vector3& vector3::operator-=(const vector3& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

vector3& vector3::operator*=(const double rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}


vector3 operator+(const vector3& lhs, const vector3& rhs)
{
    vector3 temp(lhs);
    return temp += rhs;
}

vector3 operator-(const vector3& lhs, const vector3& rhs)
{
    vector3 temp(lhs);
    return temp -= rhs;
}

vector3 operator*(const vector3& lhs, const double rhs)
{
    vector3 temp(lhs);
    return temp *= rhs;
}

vector3 operator*(const double lhs, const vector3& rhs)
{
    vector3 temp(rhs);
    return temp *= lhs;
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



// 3-vector subscript operator
double& vector4::operator[](int i)
{
    if      (i==0) {return w;}
    else if (i==1) {return x;}
    else if (i==2) {return y;}
    else if (i==3) {return z;}
    else {throw std::out_of_range("vector4 only has 4 components");}
}

const double& vector4::operator[](int i) const
{
    if      (i==0) {return w;}
    else if (i==1) {return x;}
    else if (i==2) {return y;}
    else if (i==3) {return z;}
    else {throw std::out_of_range("vector4 only has 4 components");}
}


// 4-vector arithmetic operations
vector4& vector4::operator+=(const vector4& rhs)
{
    w += rhs.w;
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

vector4& vector4::operator-=(const vector4& rhs)
{
    w -= rhs.w;
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

vector4& vector4::operator*=(const double rhs)
{
    w *= rhs;
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}


vector4 operator+(const vector4& lhs, const vector4& rhs)
{
    vector4 temp(lhs);
    return temp += rhs;
}

vector4 operator-(const vector4& lhs, const vector4& rhs)
{
    vector4 temp(lhs);
    return temp -= rhs;
}

vector4 operator*(const vector4& lhs, const double rhs)
{
    vector4 temp(lhs);
    return temp *= rhs;
}

vector4 operator*(const double lhs, const vector4& rhs)
{
    vector4 temp(rhs);
    return temp *= lhs;
}




// Vector print functions
std::ostream& operator<<(std::ostream& os, const vector3& v)
{
    return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}

std::ostream& operator<<(std::ostream& os, const vector4& v)
{
    return os << "(" << v.w << "," << v.x << "," << v.y << "," << v.z << ")";
}


// Vector magnitude functions
double mag(const vector3& v)
{
    assert(dot(v,v)>=0);// || isnan(dot(v,v)));
    return sqrt(dot(v,v));
}

double mag(const vector4& v)
{
    assert(dot(v,v)>=0);// || isnan(dot(v,v)));
    return sqrt(dot(v,v));
}


// Vector product functions
double dot(const vector3& u, const vector3& v)
{
    return u.x*v.x + u.y*v.y + u.z*v.z;
}

vector3 cross(const vector3& u, const vector3& v)
{
    return vector3(u.y*v.z - u.z*v.y,
                   u.z*v.x - u.x*v.z,
                   u.x*v.y - u.y*v.x);
}

double dot(const vector4& u, const vector4& v)
{
    return u.w*v.w - u.x*v.x - u.y*v.y - u.z*v.z;
}
