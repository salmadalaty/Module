#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created!" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = "Default idea";
    }
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copied!" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assigned!" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

// Brain::~Brain()
// {
//     std::cout << "Brain destroyed!" << std::endl;
// }

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return ideas[index];
    }
    return "";
}
