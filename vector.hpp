/* Module for vectors designed to work for particle module
 * Includes:
 *   vector3 struct (3D vector with x, y, z)
 *   vector3u struct (3D vector normalized to length 1)
 *   vector4 struct (4D vector with w, x, y, z)
 *   Functions for manipulating vectors
 *
 * Written by Ben Hokanson-Fasig for IceCube's Summer of C++ 2017
 */


//Include guard
#ifndef __VECTORS_HPP_INCLUDED__
#define __VECTORS_HPP_INCLUDED__


struct vector3
{
    double x, y, z;
};

struct vector3u
{
    const double x, y, z;
};

struct vector4
{
    double w, x, y, z;
};


#endif
