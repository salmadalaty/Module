#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:
    std::string FN;
    std::string LN;
    std::string NN;
    std::string PhN;
    std::string DS;

public:
    Contact();
    ~Contact();
    
    void setFName(std::string FN);
    void setLName(std::string LN);
    void setNName(std::string NN);
    void setPhNumber(std::string PhN);
    void setsecret(std::string DS);
    std::string getFName() const;
    std::string getLName() const;
    std::string getNN() const;
    std::string getPhNumber() const;
    std::string getsecret() const;
};

#endif