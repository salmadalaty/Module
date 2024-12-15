#include "Contact.hpp"
// intialize the constructor
Contact::Contact()
{
    FN = "";
    LN = "";
    NN = "";
    PhN = "";
    DS = "";
}
// Destructor
Contact::~Contact()
{
}

// SETTERS
void Contact::setFName(std::string fn)
{
    FN = fn;
}

void Contact::setLName(std::string ln)
{
    LN = ln;
}

void Contact::setNName(std::string nn)
{
    NN = nn;
}

void Contact::setPhNumber(std::string phn)
{
    PhN = phn;
}

void Contact::setsecret(std::string ds)
{
    DS = ds;
}

// GETTERS
std::string Contact::getFName() const
{
    return FN;
}

std::string Contact::getLName() const
{
    return LN;
}

std::string Contact::getNN() const
{
    return NN;
}

std::string Contact::getPhNumber() const
{
    return PhN;
}

std::string Contact::getsecret() const
{
    return DS;
}
