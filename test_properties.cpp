#include <iostream>
#include "properties.hpp"


void print_info(properties& p)
{
    std::cout << p.name << "(" << p.fullname << "):" << std::endl;
    std::cout << "  mass = " << p.mass << " kg" << std::endl;
    std::cout << "  charge = " << p.charge << " C" << std::endl;
    std::cout << "  spin = " << p.spin << std::endl;
}

int main()
{
    properties props0;
    print_info(props0);
    properties props1(sm_property_map[sm_particle::photon]);
    print_info(props1);
    properties props2("electron");
    print_info(props2);
}