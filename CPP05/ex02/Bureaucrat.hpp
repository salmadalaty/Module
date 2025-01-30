#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

  
    const std::string &getName() const;
    int getGrade() const;

  
    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form) const;
    void executeForm(const AForm &form) const;

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

// Overload the insertion operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
