#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *brain; // Pointer to a Brain object
public:
    Dog();
 
    Dog &operator=(const Dog &other);
    ~Dog();

    void makeSound() const;
};

#endif
