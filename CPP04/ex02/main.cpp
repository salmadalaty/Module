#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    // Animal cannot be instantiated directly anymore
    // const Animal* animal = new Animal(); // This would now be an error!
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    cat->makeSound();
    dog->makeSound();

    delete dog;
    delete cat;

    return 0;
}
