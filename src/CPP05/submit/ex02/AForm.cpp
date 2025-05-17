#include "AForm.hpp"

AForm::AForm()
    : _name("no name form")
    , _isSigned(false)
    , _requireGradeToSign(150)
    , _requireGradeToExecute(150)
{}

AForm::AForm(const AForm &other)
    : _name(other.getName())
    , _isSigned(other.getIsSigned())
    , _requireGradeToSign(other.getRequireGradeToSign())
    , _requireGradeToExecute(other.getRequireGradeToExecute())
{
    // copy constructor
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs)
{
    throw std::runtime_error("Can't use operator =.");
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

AForm::AForm(const std::string name, int requireGradeToSign, int requireGradeToExecute)
	: _name(name), _isSigned(false), _requireGradeToSign(requireGradeToSign), _requireGradeToExecute(requireGradeToExecute)
{
	if (_requireGradeToSign > 150 || _requireGradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (_requireGradeToSign < 1 || _requireGradeToExecute < 1)
		throw AForm::GradeTooHighException();
}


const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

const int &AForm::getRequireGradeToSign() const
{
    return _requireGradeToSign;
}

const int &AForm::getRequireGradeToExecute() const
{
    return _requireGradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (canSign(bureaucrat) == false)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

bool AForm::canExecute(Bureaucrat const & executor) const
{
    return (executor.getGrade() < getRequireGradeToExecute());
}

bool AForm::canSign(Bureaucrat const & signer) const
{
    return (signer.getGrade() < getRequireGradeToSign());
}

void AForm::validateCanExecute(Bureaucrat const & executor) const
{
    if (getIsSigned() == false)
        throw AForm::NotSignedException();
    if (canExecute(executor) == false)
        throw AForm::GradeTooLowException();
}


const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &o, AForm &rhs)
{
    o << "name: " << rhs.getName() << ", isSigned: " << rhs.getIsSigned()
      << ", requireGradeToSign: " << rhs.getRequireGradeToSign()
      << ", requireGradeToExecute: " << rhs.getRequireGradeToExecute();
    return o;
}
