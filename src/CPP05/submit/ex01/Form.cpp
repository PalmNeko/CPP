#include "Form.hpp"

Form::Form()
    : _name("no name form")
    , _isSigned(false)
    , _requireGradeToSign(150)
    , _requireGradeToExecute(150)
{}

Form::Form(const Form &other)
    : _name(other.getName())
    , _isSigned(other.getIsSigned())
    , _requireGradeToSign(other.getRequireGradeToSign())
    , _requireGradeToExecute(other.getRequireGradeToExecute())
{
    // copy constructor
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs)
{
    throw std::runtime_error("Can't use operator =.");
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

Form::Form(const std::string name, int requireGradeToSign, int requireGradeToExecute)
	: _name(name), _isSigned(false), _requireGradeToSign(requireGradeToSign), _requireGradeToExecute(requireGradeToExecute)
{
	if (_requireGradeToSign > 150 || _requireGradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (_requireGradeToSign < 1 || _requireGradeToExecute < 1)
		throw Form::GradeTooHighException();
}


const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

const int &Form::getRequireGradeToSign() const
{
    return _requireGradeToSign;
}

const int &Form::getRequireGradeToExecute() const
{
    return _requireGradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > getRequireGradeToSign())
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, Form &rhs)
{
    o << "name: " << rhs.getName() << ", isSigned: " << rhs.getIsSigned()
      << ", requireGradeToSign: " << rhs.getRequireGradeToSign()
      << ", requireGradeToExecute: " << rhs.getRequireGradeToExecute();
    return o;
}
