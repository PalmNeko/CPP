#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

Bureaucrat::Bureaucrat()
    : _name("no name")
    , _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name)
{
    setGrade(other._grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat Bureaucrat::operator=(const Bureaucrat &rhs)
{
    throw std::runtime_error("Can't use operator =.");
    if (this != &rhs)
    {
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    setGrade(grade);
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

void Bureaucrat::increment()
{
    setGrade(_grade - 1);
}

void Bureaucrat::decrement()
{
    setGrade(_grade + 1);
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << getName() << " couldn't sign " << form.getName() << " because "
                  << e.what() << "." << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
