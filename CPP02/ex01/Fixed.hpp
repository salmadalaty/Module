#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
class Fixed
{
private:
    int value; // store fixed_point nb
    static const int fracBit = 8;

public:
    Fixed();
    Fixed(const int intVal);              // convert from int to fp shit left
    Fixed(const float floatVal);          // convert from float to fp * 2^8
    Fixed(const Fixed &other);            // copy constructor
    Fixed &operator=(const Fixed &other); // a = b
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int raw);
    float toFloat(void) const; // convert from fixed point value to float / 2^8
    int toInt(void) const;     // convert from fixed point value to int right shift
    friend std::ostream &operator<<(std::ostream &out, const Fixed &value);
};

#endif