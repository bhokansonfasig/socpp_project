#include "uniqueid.hpp"


// Initialize counter
unsigned int uniqueID::counter = 0;


// Constructor of uniqueID
uniqueID::uniqueID() : oid(++counter) {}


// Comparison of uniqueIDs
bool uniqueID::operator==(const uniqueID& other) const
{
    return (oid==other.oid && pid==other.pid);
}


// Stream output function for uniqueID
std::ostream& operator<<(std::ostream& os, const uniqueID& id)
{
    return os << id.pid << "." << id.oid;
}
