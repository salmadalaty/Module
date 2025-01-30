#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef> // For size_t

// void (*f)(T&): a pointer to a function that takes a reference to an element of type T and returns nothing
template <typename T>
void iter(T *array, std::size_t len, void (*f)(T &))
{
    std::size_t i = 0;
    while(i < len)
    {
        f(array[i]);
        i++;
    }
}

#endif