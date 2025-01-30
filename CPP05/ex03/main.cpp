#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

    Intern Jr_Intern;
    AForm *form;

    form = Jr_Intern.makeForm("DoYouKnowMe", "Hmmmm");
    if (form != NULL)
    {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = Jr_Intern.makeForm("RobotomyRequestForm", "World");
    if (form != NULL)
    {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = Jr_Intern.makeForm("PresidentialPardonForm", "Alice");
    if (form != NULL)
    {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    form = Jr_Intern.makeForm("ShrubberyCreationForm", "Garden");
    if (form != NULL)
    {
        std::cout << form->getName() << std::endl;
        delete form;
    }

    return 0;
}
