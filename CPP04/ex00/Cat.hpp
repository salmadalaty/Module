#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    void makeSound() const;
};

#endif
