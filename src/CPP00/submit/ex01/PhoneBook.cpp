#include <string>
#include <sstream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "TableViewer.hpp"

PhoneBook::PhoneBook(void)
{
	this->currentIndex = 0;
}

void PhoneBook::addContact(const Contact &contact)
{
	this->contacts[this->currentIndex % 8] = contact;
	this->currentIndex += 1;
}

int PhoneBook::getStartIndex(void)
{
	if (this->currentIndex < 8)
		return (0);
	return (this->currentIndex - 8);
}

int PhoneBook::getEndIndex(void)
{
	return (this->currentIndex);
}

Contact& PhoneBook::getAt(int index)
{
	return (this->contacts[index % 8]);
}

bool PhoneBook::validateIndex(int index)
{
	if (index >= 0 && (this->currentIndex - 8 <= index && index < this->currentIndex))
		return (true);
	return (false);
}

size_t PhoneBook::size(void)
{
	if (this->currentIndex < 8)
		return (this->currentIndex);
	return (8);
}

void PhoneBook::show(void)
{
	TableViewer::putHeader("index", "first name", "last name", "nick name");
    for (int i = this->getStartIndex(); i < this->getEndIndex(); i++)
    {
        std::ostringstream oss;
        Contact contact(this->getAt(i));
        oss << i;
        TableViewer::putRow(oss.str(), contact.firstName, contact.lastName, contact.nickName);
    }
    TableViewer::putFooter();
}
