#include <iostream>
#include <vector>
#include "span.hpp"

int main()
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }
    catch (const Span::FullSpanException &e)
    {
        std::cout << "Exception: " << "Not enough numbers to find a span" << std::endl;
    }
}
