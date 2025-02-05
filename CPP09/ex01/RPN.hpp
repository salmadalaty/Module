#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib> // For atoi functio
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <iostream>

class RPN
{
public:
    int evaluate(const std::string &expression);
};

#endif
