#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon; // Reference to the Weapon object

public:
    HumanA(const std::string name, Weapon &weapon); // Constructor declaration
    void attack() const;                            // Attack function
};

#endif
