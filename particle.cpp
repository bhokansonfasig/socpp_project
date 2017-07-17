// #define NDEBUG
#include <cassert>
#include "particle.hpp"


// Particle constructors
particle::particle(const std::string& name)
: props_(properties(name))
{
    set_defaults();
}

particle::particle(const properties& props)
: props_(props)
{
    set_defaults();
}



// Particle defaults
void particle::set_defaults()
{
    position_ = vector4{0,0,0,0};
    momentum_ = vector4{props_.mass*c_0, 0,0,0};
}



// Particle getter functions
const vector3 particle::get_direction() const
{
    try
    {
        return vector3u(momentum_.x,momentum_.y,momentum_.z);
    }
    catch (std::domain_error& e)
    {
        // No viable direction
        return vector3(0,0,0);
    }
}

const double particle::get_energy() const
{
    return momentum_[0]*c_0;
}

const double particle::get_kinetic() const
{
    return get_energy() - props_.mass*c_0*c_0;
}



// Particle setter functions
void particle::set_position(const vector4& position)
{
    position_ = position;
}

void particle::set_position(const double time, const vector3& position)
{
    position_ = vector4(time*c_0,position.x,position.y,position.z);
}

void particle::set_momentum(const vector4& momentum)
{
    // Ignore first component since comparing doubles fails constantly
    // and simply set based on the 3-momentum
    set_momentum(vector3(momentum.x,momentum.y,momentum.z));
}

void particle::set_momentum(const vector3& momentum)
{
    momentum_ = vector4(0,momentum.x,momentum.y,momentum.z);
    // Calculate p^2 to set the energy component
    double p2 = -1*dot(momentum_,momentum_);
    assert(props_.mass*props_.mass*c_0*c_0 + p2 >= 0);
    momentum_[0] = sqrt(props_.mass*props_.mass * c_0*c_0 + p2);
}

void particle::set_momentum(const double energy, const vector3u& direction)
{
    if (energy*energy < props_.mass*props_.mass*pow(c_0,4)) {
        std::ostringstream oss;
        oss << "Energy (" << energy << ") is less than the particle's rest energy";
        throw std::invalid_argument(oss.str());
    }
    assert(energy*energy/(c_0*c_0) - props_.mass*props_.mass*c_0*c_0 >= 0);
    double pmag = sqrt(energy*energy/(c_0*c_0) - props_.mass*props_.mass*c_0*c_0);
    set_momentum(pmag * direction);
}

void particle::set_direction(const vector3u& direction)
{
    double energy = get_energy();
    // If there is no momentum, the direction is meaningless
    // To avoid unexpected results, throw an error
    if (momentum_.x==0 && momentum_.y==0 && momentum_.z==0) {
        std::ostringstream oss;
        oss << "Particle direction cannot be set when it has zero momentum. "
        << "Try using set_momentum(energy, direction) instead";
        throw std::domain_error(oss.str());
    }
    set_momentum(energy, direction);
}

void particle::set_energy(const double energy)
{
    vector3 direction = get_direction();
    // If there is no momentum, the direction is meaningless
    // And with no direction, energy alone cannot be set
    // To avoid unexpected results, throw an error
    if (momentum_.x==0 && momentum_.y==0 && momentum_.z==0) {
        std::ostringstream oss;
        oss << "Particle energy cannot be set when it has no direction. "
        << "Try using set_momentum(energy, direction) instead";
        throw std::domain_error(oss.str());
    }
    set_momentum(energy, vector3u(direction));
}

void particle::set_kinetic(const double ke)
{
    double energy = ke + props_.mass*c_0*c_0;
    set_energy(energy);
}



// Particle print function
std::ostream& operator<<(std::ostream& os, const particle& p)
{
    return os << p.get_name();
}
