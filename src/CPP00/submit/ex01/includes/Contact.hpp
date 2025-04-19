#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <ostream>

class Contact
{
    public:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact(void);
	    Contact(
            const std::string firstName,
            const std::string lastName,
            const std::string nickName,
            const std::string phoneNumber,
            const std::string darkestSecret);
		Contact(const Contact &contact);
        void show(std::ostream& os) const;
};

#endif
