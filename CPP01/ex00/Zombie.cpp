#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << "Is Destoryed!" << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ":BraiiiiiiinnnzzzZ..." << std::endl;
}