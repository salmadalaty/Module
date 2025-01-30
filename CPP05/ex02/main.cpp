#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat alice("Alice", 9);
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Bob");

        alice.signForm(shrub);
        alice.executeForm(shrub);

        alice.signForm(robot);
        alice.executeForm(robot);

        alice.signForm(pardon);
        alice.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
