#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "pb.hpp"
#include "PhoneBookError.hpp"

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
        throw PhoneBookError(errorMessage);
    if (!getInput(" Last Name\n  > ", lastName))
        throw PhoneBookError(errorMessage);
    if (!getInput(" Nick Name\n  > ", nickName))
        throw PhoneBookError(errorMessage);
    if (!getInput(" Phone Number\n  > ", phoneNumber))
        throw PhoneBookError(errorMessage);
    if (!validatePhoneNumberFormat(phoneNumber))
        throw PhoneBookError("Error: Invalid Format: " + phoneNumber);
    if (!getInput(" Darkest Secret\n  > ", darkestSecret))
        throw PhoneBookError(errorMessage);

    Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);

    return contact;
}
