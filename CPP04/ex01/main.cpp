#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int animalCount = 6;
    Animal *animals[animalCount];

    for (int i = 0; i < animalCount / 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = animalCount / 2; i < animalCount; i++)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < animalCount; i++)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < animalCount; i++)
    {
        delete animals[i];
    }

    return 0;
}
