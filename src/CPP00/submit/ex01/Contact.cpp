#include "Contact.hpp"
# include <string>
# include <ostream>

Contact::Contact(void)
    : firstName(""),
    lastName(""),
    nickName(""),
    phoneNumber(""),
    darkestSecret("")
{}

Contact::Contact(
    const std::string firstName,
    const std::string lastName,
    const std::string nickName,
    const std::string phoneNumber,
    const std::string darkestSecret)
    : firstName(firstName),
    lastName(lastName),
    nickName(nickName),
    phoneNumber(phoneNumber),
    darkestSecret(darkestSecret)
{}

Contact::Contact(const Contact &contact)
    : firstName(contact.firstName),
    lastName(contact.lastName),
    nickName(contact.nickName),
    phoneNumber(contact.phoneNumber),
    darkestSecret(contact.darkestSecret)
{}

void Contact::show(std::ostream& os) const
{
    os << "    first name : " << this->firstName << std::endl;
    os << "     last name : " << this->lastName << std::endl;
    os << "     nick name : " << this->nickName << std::endl;
    os << "  phone number : " << this->phoneNumber << std::endl;
    os << "darkest secret : " << this->darkestSecret << std::endl;
}
