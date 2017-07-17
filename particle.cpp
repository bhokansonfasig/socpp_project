#include "particle.hpp"





// Particle print function
std::ostream& operator<<(std::ostream& os, const particle& p)
{
    return os << p.get_name();
}
