/* Module for particle properties including:
 *   pprop class
 *   Default mappings between particle names and properties
 *
 * Written by Ben Hokanson-Fasig for IceCube's Summer of C++ 2017
 */



//Include guard
#ifndef __PPROP_HPP_INCLUDED__
#define __PPROP_HPP_INCLUDED__

#include <string>


class pprop
{
    private:
        int identity_;
        std::string name_;
        double mass_;
        double charge_;
        double spin_;
}


#endif
