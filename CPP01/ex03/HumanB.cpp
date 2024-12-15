#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) : name(name), weapon(weapon) {}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon; // Correct reference
}

void HumanB::attack() const
{
    if (weapon)
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl; // Use -> for pointer access
    }
    else
    {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}
