#ifndef FIXED_HPP
#define FIXED_hPP

#include <iostream>
#include <string>

class Fixed
{
private:
    int value;                          // fixed nb 256 513 128...
    static const int fractionalBit = 8; // precision 2^8

public:
    Fixed();                              // default
    Fixed(const Fixed &other);            // copy constructor
    Fixed &operator=(const Fixed &other); // a = c
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif