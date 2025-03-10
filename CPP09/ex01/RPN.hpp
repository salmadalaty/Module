#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <iostream>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression);
};

#endif
