#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// generate a random object of A B C and return a pointer to base clasee
Base *generate(void)
{
    srand(time(0));
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

// this return the type of *P if it is A B C(check the base class point on what A B C)
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}
// this return the type of &P if it is A B C(check the base class point on what A B C) but by refference
// dynamic_cast is used to safely check the type of an object at runtime,
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e)
    {
        try
        {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::exception &e)
        {
            try
            {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::exception &e)
            {
                (void)e;
                std::cerr << "Unknown class" << std::endl;
            }
        }
    }
}

int main()
{
    Base *base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}
