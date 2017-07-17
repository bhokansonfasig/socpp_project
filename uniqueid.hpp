/* Module for unique id's including uniqueID struct
 *
 * Written by Ben Hokanson-Fasig for IceCube's Summer of C++ 2017
 */

// Include guard
#ifndef __UNIQUEID_HEADER_INCLUDED__
#define __UNIQUEID_HEADER_INCLUDED__

#include <iostream>
#include <unistd.h>
// #include <sys/types.h>

struct uniqueID
{
    static unsigned int counter; // Increments for each object created
    const unsigned int oid; // Object ID based on counter
    const int pid = ::getpid(); // Set process id automatically


    // Constructor
    uniqueID();
    // Destructor
    ~uniqueID() = default;
    // Copy constructor
    uniqueID(const uniqueID&) = default;
    // Move constructor
    uniqueID(uniqueID&&) = default;
    // Copy assignment
    uniqueID& operator=(const uniqueID&) = default;
    // Move assignment
    uniqueID& operator=(uniqueID&&) = default;

    // Comparison
    bool operator==(const uniqueID& other) const; 
};

// Stream output function for uniqueID
std::ostream& operator<<(std::ostream& os, const uniqueID& id);


#endif
