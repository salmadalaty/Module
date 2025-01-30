#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}


Form::Form(const Form& other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}


Form& Form::operator=(const Form& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
    }
    return *this;
}


Form::~Form() {}


const std::string& Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}


void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getgrade() > gradeToSign) {//too low
        throw GradeTooLowException();
    }
    signedStatus = true;
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high for the form!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low for the form!";
}


void Form::validateGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}


std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form \"" << form.getName() << "\" ["
       << "Signed: " << (form.isSigned() ? "Yes" : "No") << ", "
       << "Grade to Sign: " << form.getGradeToSign() << ", "
       << "Grade to Execute: " << form.getGradeToExecute() << "]";
    return os;
}
