#include "RPN.hpp"

int RPN::evaluate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token)
    {
        if (isdigit(token[0]))
        {
            stack.push(atoi(token.c_str()));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                throw std::invalid_argument("Error");
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            int result;
            if (token == "+")
            {
                result = a + b;
            }
            else if (token == "-")
            {
                result = a - b;
            }
            else if (token == "*")
            {
                result = a * b;
            }
            else if (token == "/")
            {
                if (b == 0)
                    throw std::invalid_argument("Error");
                result = a / b;
            }
            stack.push(result);
        }
        else
        {
            throw std::invalid_argument("Error");
        }
    }

    if (stack.size() != 1)
    {
        throw std::invalid_argument("Error");
    }

    return stack.top();
}