#include "properties.hpp"
#include "sm_particles.hpp"
#include "nuc_particles.hpp"

// Properties name matching function
std::unique_ptr<base_props> properties::match_name(const std::string& name) const
{
    try {return match_name(name,sm_properties);}
    catch (bad_particle_name&)
    {
        return match_name(name,nuc_properties);
    }
}


// Properties constructors
properties::properties(const std::string& particle_name)
: name(match_name(particle_name)->get_nickname()),
  fullname(match_name(particle_name)->get_fullname()),
  mass(match_name(particle_name)->get_mass_in_kilograms()),
  charge(match_name(particle_name)->get_charge_in_coulombs()),
  spin(match_name(particle_name)->get_spin_quantum_number()) {}

properties::properties(const base_props& props)
: name(props.get_nickname()),
  fullname(props.get_fullname()),
  mass(props.get_mass_in_kilograms()),
  charge(props.get_charge_in_coulombs()),
  spin(props.get_spin_quantum_number()) {}



// Base particle properties name functions
std::string base_props::get_nickname() const
{
    if (names_.empty()) {return "";}
    else {return names_.front();}
}

std::string base_props::get_fullname() const
{
    if (names_.empty()) {return "";}
    else {return names_.back();}
}

bool base_props::name_matches(const std::string& name) const
{
    for (std::string name_ : names_)
    {
        if (name==name_) {return true;}
    }
    return false;
}

