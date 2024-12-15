#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
{
    this->name = name;
    hp = 10;
    ep = 10;
    attackDamage = 0;
    std::cout << " ClapTrap " << name << " created! " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copied!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << " ClapTrap " << name << " destroyed " << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = name;
        hp = hp;
        ep = ep;
        attackDamage = attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (ep > 0 && hp > 0)
    {
        --ep;
        std::cout << " ClapTrap " << name << " attacks " << target << ", causing" << attackDamage << "points of damage!" << std::endl;
    }
    else
    {
        std::cout << " ClapTrap " << name << " is out of energy or hit points! " << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hp -= amount;
    if (hp < 0)
        hp = 0;
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! Hit points: " << hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (ep > 0 && hp > 0)
    {
        hp += amount;
        ep--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount
                  << " points! Hit points: " << hp << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " is out of energy or hit points!" << std::endl;
    }
}
