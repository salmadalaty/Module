#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap // inherit from claptrap
{

public:
    ScavTrap(const std::string &name);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string &target);
};

#endif