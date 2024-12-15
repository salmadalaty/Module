#include "Zombie.hpp"
// creat a zombie in the stack when the function end the zombie destroyed
void randomChump(std::string name)
{
    Zombie chump(name);
    chump.announce();
}