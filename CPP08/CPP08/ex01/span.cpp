#include "span.hpp"

Span::Span(unsigned int Size) : N(Size) {}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= N)
        throw FullSpanException();
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end()); 

    int minSpan;
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        int diff = sortedNumbers[i] - sortedNumbers[i - 1];
        minSpan = std::min(minSpan, diff);
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int diff = sortedNumbers.back() - sortedNumbers.front();
    return diff;
}
