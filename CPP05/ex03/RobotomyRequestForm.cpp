#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
    std::cout << " Drilling noises " << std::endl;

    std::srand(std::time(NULL)); // (0 | 1 )for check every time different random number generated

    if (std::rand() % 2 == 0) // 50% chance of success or failure
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed on " << getTarget() << "." << std::endl;
}
