#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hp = 100;
    ep = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " Created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " Destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        --ep;
        std::cout << "FragTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << name << " has no energy or hit points left!" << std::endl;
    }
}