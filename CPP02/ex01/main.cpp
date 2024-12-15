#include "Fixed.hpp"
#include <iostream>

int main()
{
    std::cout << "Testing Default Constructor:" << std::endl;
    Fixed a;
    std::cout << "a is " << a << std::endl;
    std::cout << "a as integer is " << a.toInt() << std::endl;

    std::cout << "\nTesting Integer Constructor:" << std::endl;
    Fixed b(10);
    std::cout << "b is " << b << std::endl;
    std::cout << "b as integer is " << b.toInt() << std::endl;

    std::cout << "\nTesting Float Constructor:" << std::endl;
    Fixed c(42.42f);
    std::cout << "c is " << c << std::endl;
    std::cout << "c as integer is " << c.toInt() << std::endl;

    std::cout << "\nTesting Copy Constructor:" << std::endl;
    Fixed d(b);
    std::cout << "d is " << d << std::endl;
    std::cout << "d as integer is " << d.toInt() << std::endl;

    std::cout << "\nTesting Copy Assignment Operator:" << std::endl;
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "a as integer is " << a.toInt() << std::endl;

    std::cout << "\nTesting toFloat() and toInt():" << std::endl;
    std::cout << "c as float is " << c.toFloat() << std::endl;
    std::cout << "c as integer is " << c.toInt() << std::endl;

    return 0;
}
