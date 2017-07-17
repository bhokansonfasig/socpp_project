#include "uniqueid.hpp"

int main()
{
    uniqueID id1, id2, id3;
    std::cout << "id1 = " << id1 << "\nid3 = " << id3 << std::endl;
    std::cout << "id1==id1? " << (id1==id1?"True":"False") << std::endl;
    std::cout << "id1==id2? " << (id1==id2?"True":"False") << std::endl;
}
