#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    // First test: HumanA with a weapon
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack(); // Bob attacks with their crude spiked club
        club.setType("some other type of club");
        bob.attack(); // Bob attacks with their some other type of club
    }

    // Second test: HumanB with a weapon
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim", &club);
        jim.attack(); // Jim attacks with their crude spiked club
        club.setType("some other type of club");
        jim.attack(); // Jim attacks with their some other type of club
    }

    return 0;
}
