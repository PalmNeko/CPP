#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "phonebook.hpp"

#include <iostream>

Contact getContactFromStdin(void);

void addContactRoutine(PhoneBook& phoneBook)
{
    std::cout << "Let's make contact!!!" << std::endl;
    std::cout << "Please Input personal information." << std::endl;

    const Contact contact = getContactFromStdin();
    
    phoneBook.addContact(contact);

    return ;
}

Contact getContactFromStdin(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::string errorMessage = "Error: No input provided. Exiting...";

    if (!getInput(" First Name\n  > ", firstName))
        throw std::runtime_error(errorMessage);
    if (!getInput(" Last Name\n  > ", lastName))
        throw std::runtime_error(errorMessage);
    if (!getInput(" Nick Name\n  > ", nickName))
        throw std::runtime_error(errorMessage);
    if (!getInput(" Phone Number\n  > ", phoneNumber))
        throw std::runtime_error(errorMessage);
    if (!validatePhoneNumberFormat(phoneNumber))
        throw std::runtime_error("Error: Invalid Format: " + phoneNumber);
    if (!getInput(" Darkest Secret\n  > ", darkestSecret))
        throw std::runtime_error(errorMessage);

    Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);

    return contact;
}