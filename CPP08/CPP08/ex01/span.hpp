#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename InputIterator>
    void addRange(InputIterator start, InputIterator end)
    {
        for (InputIterator it = start; it != end; ++it)
        {
            addNumber(*it);
        }
    }

    class FullSpanException : public std::exception
    {
        const char *what() const throw() { return "Span is already full."; }
    };
    class NoSpanException : public std::exception
    {
        const char *what() const throw() { return "Not enough numbers to find a span."; }
    };
};

#endif
