
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    RangeGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << " is destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        grade = other.grade;
    }
    return *this;
}



const std::string Bureaucrat::getname() const {
    return name;
}

int Bureaucrat::getgrade() const{
    return grade;
}

void Bureaucrat::increment()
{
    RangeGrade(grade - 1);
    grade--;
}

void Bureaucrat::decrement()
{
    RangeGrade(grade + 1);
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

void Bureaucrat::RangeGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getname() << ", bureaucrat grade " << bureaucrat.getgrade();
    return os;
}