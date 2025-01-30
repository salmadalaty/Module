#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::list<int> test; // container
    test.push_back(155); // add to the end
    test.push_back(156);
    test.push_back(157);

    std::list<int>::const_iterator it = test.end();

    try
    {
        it = ::easyfind(test, 155);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    if (it != test.end())
        std::cout << *it << " found" << std::endl;

    it = test.end();

    try
    {
        it = ::easyfind(test, 15);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    if (it != test.end())
        std::cout << *it << " found" << std::endl;

    return (0);
}