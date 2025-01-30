#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this;

    return *this;
}

void ScalarConverter::convert(const std::string &literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
    }

    std::stringstream ssDouble(literal);
    if (ssDouble >> d && ssDouble.eof())
    {
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);

        if (d == std::floor(d) && d >= 0 && d <= 127 && std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else if (d == std::floor(d) && d >= 0 && d <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
            std::cout << "int: " << i << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

        return;
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
