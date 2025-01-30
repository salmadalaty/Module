#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
    std::string target;

public:
    
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();


    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& bureaucrat);

  
    void execute(const Bureaucrat& executor) const;
    virtual void action() const = 0; // Pure virtual method

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};


std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
