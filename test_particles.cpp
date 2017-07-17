#include <iostream>
#include "particle.hpp"


void print_info(particle& p)
{
    std::cout << p << ":" << std::endl;
    std::cout << "  Mass       = " << p.get_mass() << std::endl;
    std::cout << "  Charge     = " << p.get_charge() << std::endl;
    std::cout << "  Spin       = " << p.get_spin() << std::endl;
    std::cout << "  Position   = " << p.get_position() << std::endl;
    std::cout << "  Momentum   = " << p.get_momentum() << std::endl;
}



int main()
{
    particle part0;
    print_info(part0);
}