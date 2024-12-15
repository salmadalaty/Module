#include "Zombie.hpp"
// create a zombie in the heap so manual deleted
Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}