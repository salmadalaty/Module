#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> //for container (find, sort..)
#include <iterator>  //for (begin , end..)
#include <stdexcept> //for the runtime_error logic_Err,..

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Element not found");
    }
    return it;
}

#endif
