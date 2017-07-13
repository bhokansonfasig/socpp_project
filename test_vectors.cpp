#include <iostream>
#include "vector.hpp"

int main()
{
    std::cout << "Test vector3 default construction: ";
    vector3 v;
    std::cout << v << std::endl;

    std::cout << "Test vector3 member assignment: ";
    v.x = 1;
    std::cout << v << std::endl;

    std::cout << "Test vector3 subscript assignment: ";
    v[1] = 2;
    std::cout << v << std::endl;

    std::cout << "Test vector3 dot product: ";
    std::cout << v << "*" << vector3(0,1,0) << "=" << dot(v,vector3(0,1,0)) << std::endl;

    std::cout << "Test vector3u default construction: ";
    vector3u u;
    std::cout << u << std::endl;

    // Assigning to a member of u should cause an error
    // u.x = 1;
}