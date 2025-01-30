#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"
class Bureaucrat
{

private:
    const std::string name;
    int grade;
    void RangeGrade(int grade); //to ensure the grade between 1 and 150

public:
    Bureaucrat(const std::string& name, int grade);//constr
    Bureaucrat(const Bureaucrat& other);//copy of the constr
    Bureaucrat& operator=(const Bureaucrat& other);//to allow one bureaucrat it = to another one
    ~Bureaucrat(); //desrt
    const std::string getname() const;
    int getgrade()const;

    void increment();
    void decrement();
void signForm(Form& form) const;
    //custom expection clases 
    //what is the grade of the bureaucrat (to hight || to low)
    // const because we dont want to change the grade of the bureaucrat
    //throw exception if grade is to hight or to low
    //this 2 clases are inherit from std::exception (<stdexcept>) (try catch)


    class GradeTooHighException : public std::exception //if the grade is < 1
    {
        public:
        const char* what() const throw();
        };
        class GradeTooLowException : public std::exception //if the grade is > 150
        {
            public:
            const char* what() const throw();
        };


};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
        
#endif