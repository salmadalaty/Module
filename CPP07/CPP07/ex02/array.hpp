#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    unsigned int size() const
    {
        return _size;
    }

    Array() : _elements(NULL), _size(0) {}

    Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

    Array(const Array &other) : _elements(NULL), _size(0)
    {
        *this = other;
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _elements;
            _size = other._size;
            _elements = new T[_size];
            unsigned int i = 0;
            while (i < _size)
            {
                _elements[i] = other._elements[i];
                i++;
            }
        }
        return *this;
    }

    ~Array()
    {
        delete[] _elements;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
};

#endif
