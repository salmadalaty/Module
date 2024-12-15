#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{

public:
    std::string name;
    int hp;
    int ep;
    int attackDamage;
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);            // copy of constructor
    ClapTrap &operator=(const ClapTrap &other); // obj=obj
    ~ClapTrap();
    void attack(const std::string &target); // Reduce energy points and print the attack message
    void takeDamage(unsigned int amount);   // Reduce hit points and print the damage message
    void beRepaired(unsigned int amount);   // Increase hit points, reduce energy points, and print the repair message.
};

#endif