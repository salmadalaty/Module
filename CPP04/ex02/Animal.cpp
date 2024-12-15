#include "Animal.hpp"

Animal::Animal() : type("Animal") {}
Animal::~Animal() {}

std::string Animal::getType() const
{
    return type;
}