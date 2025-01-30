#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), signedStatus(other.signedStatus),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
        target = other.target;
    }
    return *this;
}


AForm::~AForm() {}


const std::string& AForm::getName() const
 { 
    return name;
}


bool AForm::isSigned() const 
{ 
    return signedStatus;
}
int AForm::getGradeToSign() const
 { 
    return gradeToSign;
 }
int AForm::getGradeToExecute() const
{ 
    return gradeToExecute;
}
const std::string& AForm::getTarget() const
 { 
    return target;
 }


void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    signedStatus = true;
}


void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    action(); 
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form \"" << form.getName() << "\" [Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute() << "]";
    return os;
}
