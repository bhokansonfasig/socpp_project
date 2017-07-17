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

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include "properties.hpp"
#include "uniqueid.hpp"
#include "vector.hpp"

const double c_0 = 299792458;


class particle
{
    public:
        // Constructors
        particle() = default;
        explicit particle(const std::string& name);
        explicit particle(const properties& props);
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
        const uniqueID get_id() const {return id_;}
        const std::string get_name() const {return props_.name;}
        const std::string get_fullname() const {return props_.fullname;}
        const double get_mass() const {return props_.mass;}
        const double get_charge() const {return props_.charge;}
        const double get_spin() const {return props_.spin;}
        const vector4 get_position() const {return position_;}
        const vector4 get_momentum() const {return momentum_;}
        const vector3 get_direction() const;
        const double get_energy() const;
        const double get_kinetic() const;

        // Setter functions
        void set_position(const vector4& position);
        void set_position(const double time, const vector3& position);
        void set_momentum(const vector4& momentum);
        void set_momentum(const vector3& momentum);
        void set_momentum(const double energy, const vector3u& direction);
        void set_direction(const vector3u& direction);
        void set_energy(const double energy);
        void set_kinetic(const double ke);


    private:
        const uniqueID id_;
        properties props_;
        vector4 position_;
        vector4 momentum_;

        void set_defaults();
};



// Particle print function
std::ostream& operator<<(std::ostream& os, const particle& p);


#endif
