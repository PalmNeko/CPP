#include "PhoneBookError.hpp"

/*
 * special member functions
 */
PhoneBookError::PhoneBookError(void)
{}

PhoneBookError::PhoneBookError(const PhoneBookError& phoneBookError)
    :_msg(phoneBookError._msg)
{}

PhoneBookError::~PhoneBookError(void) _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{}

/*
 * others: public
 */
PhoneBookError::PhoneBookError(const std::string& msg)
    : _msg(msg)
{}

const char *PhoneBookError::what(void) const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return this->_msg.c_str();
}

/*
 * operators
 */
PhoneBookError& PhoneBookError::operator=(const PhoneBookError& phoneBookError)
{
    if (this != &phoneBookError)
    {
        this->_msg = phoneBookError._msg;
    }
    return *this;
}

/*
 * others: private
 */
