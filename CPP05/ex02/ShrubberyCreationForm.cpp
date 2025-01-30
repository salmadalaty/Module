#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
    std::ofstream ofs((getTarget() + "_shrubbery").c_str()); // Convert to const char*

    if (ofs.is_open())
    {
        ofs << "        ccee88oo          \n"
               "  C8O8O8Q8PoOb o8oo      \n"
               " dOB69QO8PdUOpugoO9bD    \n"
               "CgggbU8OU qOp qOdoUOdcb  \n"
               "    6OuU  /p u gcoUodpP  \n"
               "      \\\\//  /douUP       \n"
               "        ||||||           \n"
               "        ||||||           \n"
               "        ||||||           \n"
               "  .....//||||\\\\....       \n";
        ofs.close();
    }
    else
    {
        throw std::ios_base::failure("Failed to open the file.");
    }
}
