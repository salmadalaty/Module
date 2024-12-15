#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp" // Include Weapon.hpp correctly

class HumanB
{
private:
    std::string name;
    Weapon *weapon; // Use Weapon with uppercase 'W'

public:
    HumanB(std::string name, Weapon *weapon); // Correct constructor definition
    void attack() const;
    void setWeapon(Weapon &weapon); // Correct reference to Weapon
};

#endif
