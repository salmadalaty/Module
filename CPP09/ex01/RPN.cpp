#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        std::cout << "RPN copy assignment operator called." << std::endl;
    }
    return *this;
}

RPN::~RPN()
{
}

int RPN::evaluate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token)
    {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1])))
        {
            stack.push(atoi(token.c_str()));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                throw std::invalid_argument("Error: Not enough operands.");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            int result;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
            {
                if (b == 0)
                    throw std::invalid_argument("Error: Division by zero.");
                result = a / b;
            }
            stack.push(result);
        }
        else
        {
            throw std::invalid_argument("Error: Invalid token in expression.");
        }
    }

    if (stack.size() != 1)
    {
        throw std::invalid_argument("Error: Invalid RPN expression.");
    }

    return stack.top();
}
