#include "Fixed.hpp"

Fixed::~Fixed()
{
    std::cout << " Destructor called" << std::endl;
}

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal)
{
    std::cout << "Int constructor called" << std::endl;
    value = intVal << fracBit; // shift left
}

Fixed::Fixed(const float floatVal)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(floatVal * (1 << fracBit)); // scale and round
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        value = other.value;
    }
    return *this; // return curent obj
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fracBit); // divide by 2^8
}

int Fixed::toInt(void) const
{
    return value >> fracBit; // shift right
}

int Fixed::getRawBits() const
{
    return value;
}

void Fixed::setRawBits(int raw)
{
    value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat(); // Output as floating-point value
    return out;
}