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

#include <iostream>
#include "vector.hpp"
#include "properties.hpp"

class particle
{
    public:
        // Constructor
        particle() = default;
        // Destructor
        ~particle() = default;
        // Copy Constructor
        particle(const particle&) = default;
        // Move Constructor
        particle(particle&&) = default;
        // Copy Assignment
        particle& operator=(const particle&) = default;
        // Move Assignment
        particle& operator=(particle&&) = default;

        // Getter functions
        const std::string get_name() const {return props_.name;}
        const std::string get_fullname() const {return props_.fullname;}
        const double get_mass() const {return props_.mass;}
        const double get_charge() const {return props_.charge;}
        const double get_spin() const {return props_.spin;}
        const vector4 get_position() const {return position_;}
        const vector4 get_momentum() const {return momentum_;}


    private:
        properties props_;
        vector4 position_;
        vector4 momentum_;
};



// Particle print function
std::ostream& operator<<(std::ostream& os, const particle& p);


#endif
