/* Module for particles including:
 *   particle class
 *   Functions for interacting with particle class
 * Note that, for better or worse, all values are in SI (mks)
 *
 * Written by Ben Hokanson-Fasig for IceCube's Summer of C++ 2017
 */



//Include guard
#ifndef __PARTICLE_HPP_INCLUDED__
#define __PARTICLE_HPP_INCLUDED__

#include "vector.hpp"
#include "pprop.hpp"

class particle
{
    private:
        pprop properties_;
        vector4 position_;
        vector4 momentum_;
};


#endif
