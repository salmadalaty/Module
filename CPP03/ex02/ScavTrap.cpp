#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{

    hp = 100;
    ep = 50;
    attackDamage = 20;
    std::cout << " ScarvTrap " << name << " Created! " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << " ScarvTrap " << name << " Destroyed! " << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        --ep;
        std::cout << "ScavTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << name << " has no energy or hit points left!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}