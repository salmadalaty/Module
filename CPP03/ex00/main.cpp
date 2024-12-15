#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clappy");

    clap.attack("Target A");
    clap.takeDamage(5);
    clap.beRepaired(3);

    clap.attack("Target B");
    clap.takeDamage(10);
    clap.beRepaired(5);

    return 0;
}
