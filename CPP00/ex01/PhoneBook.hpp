#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
private:
    Contact contact[8]; // 8 object of contact have the innfo of phone
    int max_contact;    // size =8
    int nb_index;       // for check if = 8 or not (index)
    int nb_contact; //total contact

public:
    PhoneBook();
    ~PhoneBook();
    void ADD();
    void Search() const;
};

#endif