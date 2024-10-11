#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "TableViewer.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

void addContactRoutine(PhoneBook& phoneBook);
void searchContactRoutine(PhoneBook& phoneBook);
static bool getInput(const std::string& prompt, std::string& input);

int main(void)
{
    std::string command;
    PhoneBook phoneBook = PhoneBook();

    while (true)
    {
        std::cout << "command ADD / SEARCH / EXIT > ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl;
            break ;
        }
        if (command == "ADD")
            addContactRoutine(phoneBook);
        else if (command == "SEARCH")
            searchContactRoutine(phoneBook);
        else if (command == "EXIT")
            break ;
    }
    return (0);
}

void addContactRoutine(PhoneBook& phoneBook)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Let's make contact!!!" << std::endl;
    std::cout << "Please Input personal information." << std::endl;
    if (getInput(" First Name\n  > ", firstName)
        && getInput(" Last Name\n  > ", lastName)
        && getInput(" Nick Name\n  > ", nickName)
        && getInput(" Phone Number\n  > ", phoneNumber)
        && getInput(" Darkest Secret\n  > ", darkestSecret))
    {
        const Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
        phoneBook.addContact(contact);
    }
    return ;
}

void searchContactRoutine(PhoneBook& phoneBook)
{
    if (phoneBook.size() == 0)
    {
        std::cout << "It has no contacts." << std::endl;
        return ;
    }
    std::cout << "Search and Show" << std::endl;
    phoneBook.show();
    std::string selectedIndex;
    std::cout << "Please select index > ";
    if (std::getline(std::cin, selectedIndex))
    {
        int index;
        std::istringstream iss(selectedIndex);

        iss >> index;
        if (phoneBook.validateIndex(index))
        {
            Contact contact(phoneBook.getAt(index));
            contact.show(std::cout);
        }
        else
            std::cout << "Out of range: " << selectedIndex << std::endl;
    }
    return ;
}

static bool getInput(const std::string& prompt, std::string& input)
{
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "No input provided. Exiting..." << std::endl;
        return (false);
    }
    return (true);
}
