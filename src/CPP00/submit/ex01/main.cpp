#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "TableViewer.hpp"
#include "phonebook.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

int main(void)
{
    PhoneBook phoneBook = PhoneBook();

    while (true)
    {
        std::string command;
        if (!getInput("command ADD / SEARCH / EXIT > ", command))
        {
            std::cout << std::endl;
            break ;
        }
        try
        {
            if (command == "ADD")
                addContactRoutine(phoneBook);
            else if (command == "SEARCH")
                searchContactRoutine(phoneBook);
            else if (command == "EXIT")
                break ;
        }
        catch (const std::runtime_error& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return (0);
}
