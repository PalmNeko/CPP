#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact contacts[8];
	private:
		int currentIndex;
	public:
		PhoneBook(void);
		void addContact(const Contact& contact);
		int getStartIndex(void);
		int getEndIndex(void);
		Contact& getAt(int index);
		bool validateIndex(int index);
		size_t size(void);
		void show(void);
};

#endif
