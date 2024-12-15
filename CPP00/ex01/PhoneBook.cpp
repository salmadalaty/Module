#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> // For std::setw and std::right

PhoneBook::PhoneBook()
{
    max_contact = 8;
    nb_index = 0;
    nb_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::ADD()
{
    std::string fname, lname, nname, phnumber, secret;

    if (nb_contact >= max_contact)
    {
        std::cout << "Phonebook is full. Cannot add more contacts." << std::endl;
        return;
    }

    std::cout << "Enter First Name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lname);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phnumber);
    std::cout << "Enter Secret: ";
    std::getline(std::cin, secret);

    contact[nb_index].setFName(fname);
    contact[nb_index].setLName(lname);
    contact[nb_index].setNName(nname);
    contact[nb_index].setPhNumber(phnumber);
    contact[nb_index].setsecret(secret);

    nb_contact++;

    nb_index = (nb_index + 1) % max_contact;
}

void PhoneBook::Search() const
{
    if (nb_contact == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::right << "Index"
              << "|"
              << std::setw(10) << std::right << "First Name"
              << "|"
              << std::setw(10) << std::right << "Last Name"
              << "|"
              << std::setw(10) << std::right << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < nb_contact; i++)
    {
        std::cout << std::setw(10) << std::right << i
                  << "|"
                  << std::setw(10) << std::right << (contact[i].getFName().size() > 10 ? contact[i].getFName().substr(0, 9) + "." : contact[i].getFName())
                  << "|"
                  << std::setw(10) << std::right << (contact[i].getLName().size() > 10 ? contact[i].getLName().substr(0, 9) + "." : contact[i].getLName())
                  << "|"
                  << std::setw(10) << std::right << (contact[i].getNN().size() > 10 ? contact[i].getNN().substr(0, 9) + "." : contact[i].getNN())
                  << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;

    int index;
    std::cout << "Enter index to view full contact details (0-" << nb_contact - 1 << "): ";
    std::cin >> index;
    std::cin.ignore();

    if (index < 0 || index >= nb_contact)
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "Full contact details for index " << index << ":" << std::endl;
    std::cout << "First Name: " << contact[index].getFName() << std::endl;
    std::cout << "Last Name: " << contact[index].getLName() << std::endl;
    std::cout << "Nickname: " << contact[index].getNN() << std::endl;
    std::cout << "Phone Number: " << contact[index].getPhNumber() << std::endl;
    std::cout << "Secret: " << contact[index].getsecret() << std::endl;
}
