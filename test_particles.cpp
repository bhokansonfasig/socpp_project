#include <iostream>
#include "particle.hpp"


void print_info(particle& p)
{
    std::cout << p << std::endl;
    std::cout << "  Mass       = " << p.get_mass() << " kg" << std::endl;
    std::cout << "  Charge     = " << p.get_charge() << " C" << std::endl;
    std::cout << "  Spin       = " << p.get_spin() << std::endl;
    std::cout << "  Position   = " << p.get_position() << " m" << std::endl;
    std::cout << "  Momentum   = " << p.get_momentum() << " kg m/s" << std::endl;
    std::cout << "  Direction  = " << p.get_direction() << std::endl;
    std::cout << "  Energy     = " << p.get_energy() << " J" << std::endl;
    std::cout << "  Kinetic    = " << p.get_kinetic() << " J" << std::endl;
}


template <typename T>
void print_title(T s)
{
    std::cout << "\n=====" << s << "=====" << std::endl;
}


int main()
{
    print_title("Build default particle");
    particle part0;
    print_info(part0);

    print_title("Build default electron");
    particle part1{"electron"};
    print_info(part1);

    print_title("Build electron based on first's name and set position with vector4");
    particle part2{part1.get_name()};
    part2.set_position(vector4{0,10,10,10});
    print_info(part2);

    print_title("Build proton and set position with values");
    particle part3{"proton"};
    part3.set_position({0,1,1,0});
    print_info(part3);

    print_title("Set proton's momentum with vector3");
    part3.set_momentum(vector3{0,0,1e-18});
    print_info(part3);

    print_title("Reset proton direction downward");
    part3.set_direction(vector3u{0,0,-1});
    print_info(part3);

    print_title("Set proton energy to 1 GeV");
    part3.set_energy(1.6e-10);
    print_info(part3);

    print_title("Set proton energy to mc^2");
    part3.set_energy(part3.get_mass()*c_0*c_0);
    print_info(part3);

    print_title("Set proton KE to 0");
    part3.set_kinetic(0);
    print_info(part3);
}