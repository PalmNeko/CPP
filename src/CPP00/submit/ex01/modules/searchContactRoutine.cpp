#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "PhoneBookError.hpp"
#include "pb.hpp"

#include <string>
#include <sstream>
#include <iostream>

void searchContactRoutine(PhoneBook& phoneBook)
{
    if (phoneBook.size() == 0)
        throw PhoneBookError("Error: It has no contacts.");
    std::cout << "Search and Show" << std::endl;
    phoneBook.show();

    std::string selectedIndex;
    if (getInput("Please select index > ", selectedIndex) == false)
        return ;
    if (validateStrictNumberFormat(selectedIndex) == false)
        throw PhoneBookError("Error: Invalid number format");
    int index;
    std::istringstream iss(selectedIndex);
    iss >> index;
    if (!selectedIndex.empty() && phoneBook.validateIndex(index))
    {
        Contact contact(phoneBook.getAt(index));
        contact.show(std::cout);
    }
    else
        throw PhoneBookError("Error: Out of range: " + selectedIndex);
    return ;
}
