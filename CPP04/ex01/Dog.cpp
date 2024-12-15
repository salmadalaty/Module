#include "Dog.hpp"

Dog::Dog()
{
    type = "DOG";
    std::cout << " DOG CREATED! " << std::endl;
}

Dog::~Dog()
{
    std::cout << " DOG DESTROYED! " << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}