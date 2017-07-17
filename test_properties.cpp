#include <iostream>
#include "properties.hpp"
#include "sm_particles.hpp"


void print_info(properties& p)
{
    std::cout << p.name << " (" << p.fullname << "):" << std::endl;
    std::cout << "  mass = " << p.mass << " kg" << std::endl;
    std::cout << "  charge = " << p.charge << " C" << std::endl;
    std::cout << "  spin = " << p.spin << std::endl;
}

int main()
{
    properties props0;
    print_info(props0);
    properties props1(sm_properties[sm_particle::W_m]);
    print_info(props1);
    properties props2("electron");
    print_info(props2);
    properties props3("proton");
    print_info(props3);
    properties props4("H-1 nucleus");
    print_info(props4);
    properties props5("Ca-43 nucleus");
    print_info(props5);
}