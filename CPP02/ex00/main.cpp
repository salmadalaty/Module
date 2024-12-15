#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = a;

    std::cout << "Raw value of a: " << a.getRawBits() << std::endl;
    std::cout << "Raw value of b: " << b.getRawBits() << std::endl;
    std::cout << "Raw value of c: " << c.getRawBits() << std::endl;

    return 0;
}
