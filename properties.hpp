/* Module for particle properties including:
 *   General properties struct
 *   Default mappings between particle names and properties
 *   Inheritable base_prop class and children to use in maps
 *   Scoped enums of particle names
 *
 * Written by Ben Hokanson-Fasig for IceCube's Summer of C++ 2017
 */



//Include guard
#ifndef __PPROP_HPP_INCLUDED__
#define __PPROP_HPP_INCLUDED__

#include <string>
#include <vector>
#include <map>
#include <memory>


// Error for unknown particle name
class bad_particle_name: public std::exception
{
    public:
        bad_particle_name(const std::string& name) : name_(name) {}
    
    private:
        std::string name_ = "";

        const char* what() const throw() {
            std::string message;
            if (name_=="") {message = "Given particle";}
            else {message = name_;}
            message += " is not a Standard Model particle";
            return message.c_str();
        }
};



// Base class for properties in maps
class base_props
{
    public:
        // Constructor
        base_props(std::vector<std::string> names={""}, double mass=0, double charge=0, double spin=0)
        : names_(names), mass_(mass), charge_(charge), spin_(spin) {}
        // Destructor
        ~base_props() = default;
        // Copy Constructor
        base_props(const base_props&) = default;
        // Move Constructor
        base_props(base_props&&) = default;
        // Copy Assignment
        base_props& operator=(const base_props&) = default;
        // Move Assignment
        base_props& operator=(base_props&&) = default;

        // Getter functions
        virtual const std::string get_nickname() const;
        virtual const std::string get_fullname() const;
        virtual const double get_mass_in_kilograms() const {return mass_;}
        virtual const double get_charge_in_coulombs() const {return charge_;}
        virtual const double get_spin_quantum_number() const {return spin_;}

        virtual const bool name_matches(const std::string& name) const;

    protected:
        std::vector<std::string> names_;
        double mass_;
        double charge_;
        double spin_;
};


// Main properties struct
struct properties
{
    public:
        // Constructors
        explicit properties(const std::string& particle_name);
        explicit properties(const base_props& props=base_props{{"null","unknown"},0,0,0});
        // Destructor
        ~properties() = default;
        // Copy Constructor
        properties(const properties&) = default;
        // Move Constructor
        properties(properties&&) = default;
        // Copy Assignment
        properties& operator=(const properties&) = default;
        // Move Assignment
        properties& operator=(properties&&) = default;

        // Name matching function
        template <typename T, typename U>
        std::unique_ptr<U> match_name(const std::string& name, const std::map<T,U>& map) const
        {
            for (std::pair<T,U> prop_pair : map)
            {
                if (prop_pair.second.name_matches(name))
                {
                    return std::make_unique<U>(prop_pair.second);
                }
            }
            throw bad_particle_name(name);
        }
        std::unique_ptr<base_props> match_name(const std::string& name) const;

        const std::string name;
        const std::string fullname;
        const double mass;
        const double charge;
        const double spin;
};


#endif
