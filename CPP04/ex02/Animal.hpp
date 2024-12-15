#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>
#include <string>

// Animal.hpp
class Animal
{
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other) = delete;
    Animal &operator=(const Animal &other) = delete;
    virtual void makeSound() const = 0;
    std::string getType() const; // Declaration only
};

#endif
