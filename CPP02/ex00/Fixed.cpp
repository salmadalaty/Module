#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor" << std::endl;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &other) // if ob1 = ob2
    {
        this->value = other.value;
    }
    return *this;
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int raw)
{
    this->value = raw;
}