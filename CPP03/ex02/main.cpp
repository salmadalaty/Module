#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{

    FragTrap frag("Fraggy");

    frag.attack("Target A");
    frag.highFivesGuys();
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.attack("Target B");
    frag.takeDamage(100);
    frag.beRepaired(10);

    return 0;
}
