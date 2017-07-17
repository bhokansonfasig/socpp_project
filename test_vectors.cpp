#include <iostream>
#include "vector.hpp"

int main()
{
    std::cout << "---------- Testing vector3 ----------" << std::endl;
    std::cout << "Test default construction: ";
    vector3 v;
    std::cout << v << std::endl;

    std::cout << "Test member assignment: ";
    v.x = 1;
    std::cout << v << std::endl;

    std::cout << "Test subscript assignment: ";
    v[1] = 2;
    std::cout << v << std::endl;

    std::cout << "Test addition: ";
    std::cout << v << "+" << vector3(0,1,0) << "=" << v+vector3(0,1,0) << std::endl;

    std::cout << "Test subtraction: ";
    std::cout << v << "-" << vector3(0,1,0) << "=" << v-vector3(0,1,0) << std::endl;

    std::cout << "Test scalar multiplication: ";
    std::cout << v << "*2=" << v*2 << "=" << 2*v << std::endl;

    std::cout << "Test dot product: ";
    std::cout << v << "*" << vector3(0,1,0) << "=" << dot(v,vector3(0,1,0)) << std::endl;

    std::cout << "Test cross product: ";
    std::cout << v << "x" << vector3(0,1,0) << "=" << cross(v,vector3(0,1,0)) << std::endl;


    std::cout << "\n---------- Testing vector3u ----------" << std::endl;
    std::cout << "Test default construction: ";
    vector3u u;
    std::cout << u << std::endl;

    std::cout << "Test construction from vector3: ";
    vector3u u2{vector3(1,1,0)};
    std::cout << u2 << std::endl;

    // Assigning to a member of u should cause an error
    // u.x = 1;

    std::cout << "Test addition: ";
    std::cout << u << "+" << vector3(0,1,0) << "=" << u+vector3(0,1,0) << std::endl;

    std::cout << "Test subtraction: ";
    std::cout << u << "-" << vector3(0,1,0) << "=" << u-vector3(0,1,0) << std::endl;

    std::cout << "Test scalar multiplication: ";
    std::cout << u << "*2=" << u*2 << "=" << 2*u << std::endl;

    std::cout << "Test dot product: ";
    std::cout << u << "*" << vector3(0,1,0) << "=" << dot(u,vector3(0,1,0)) << std::endl;

    std::cout << "Test cross product: ";
    std::cout << u << "x" << vector3(0,1,0) << "=" << cross(u,vector3(0,1,0)) << std::endl;

    // Trying to normalize (0,0,0) should cause an error
    // vector3u u3{0,0,0};


    std::cout << "\n---------- Testing vector4 ----------" << std::endl;
    std::cout << "Test default construction: ";
    vector4 w;
    std::cout << w << std::endl;

    std::cout << "Test member assignment: ";
    w.w = 2;
    w.x = 1;
    std::cout << w << std::endl;

    std::cout << "Test subscript assignment: ";
    w[2] = 2;
    std::cout << w << std::endl;

    std::cout << "Test addition: ";
    std::cout << w << "+" << vector4(0,0,1,0) << "=" << w+vector4(0,0,1,0) << std::endl;

    std::cout << "Test subtraction: ";
    std::cout << w << "-" << vector4(0,0,1,0) << "=" << w-vector4(0,0,1,0) << std::endl;

    std::cout << "Test scalar multiplication: ";
    std::cout << w << "*2=" << w*2 << "=" << 2*w << std::endl;

    std::cout << "Test dot product: ";
    std::cout << w << "*" << vector4(0,0,1,0) << "=" << dot(w,vector4(0,0,1,0)) << std::endl;
}