#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Scavy");

    scav.attack("Target A");
    scav.guardGate();
    scav.takeDamage(50);
    scav.beRepaired(20);
    scav.attack("Target B");
    scav.takeDamage(80);

    return 0;
}
