#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal created" << std::endl;
}

Animal::~Animal()
{
    std::cout << " Animal Destroyed! " << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}