#ifndef PHONE_BOOK_ERROR_HPP
# define PHONE_BOOK_ERROR_HPP

# include <exception>
# include <string>

class PhoneBookError: public std::exception
{
    // variables
    public:
    private:
        std::string _msg;
    // functions
    public:
        // special member functions
        PhoneBookError(void); // default constructor
        PhoneBookError(const PhoneBookError& phoneBookError); // copy constructor
        virtual ~PhoneBookError(void) _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW; // destructor
        // others
        PhoneBookError(const std::string& msg);
        virtual const char* what(void) const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
        // operators
        PhoneBookError& operator=(const PhoneBookError& phoneBookError); // copy assignment operator
    private:
};

#endif
